/************************************************************************
* CopyRight: LLC All Rights Reserved
* Title: main.cpp
* author: LLC
* date: 2016/4/20
* version: V1.0
************************************************************************/

#include <windows.h>
#include <iostream>
using namespace std;

DWORD WINAPI Fun1Proc(LPVOID lpParameter);//thread data
DWORD WINAPI Fun2Proc(LPVOID lpParameter);//thread data

int tickets=100;
HANDLE g_hEvent;

void main(){
	HANDLE hThread1; HANDLE hThread2;
	//创建人工重置事件内核对象 
	g_hEvent=CreateEvent(NULL,FALSE,FALSE,"tickets");
	if (g_hEvent) {
		if (ERROR_ALREADY_EXISTS==GetLastError()) {
			cout<<"only one instance can run!"<<endl;
			return;
		}
	}
	SetEvent(g_hEvent);
	//创建线程 
	hThread1=CreateThread(NULL,0,Fun1Proc,NULL,0,NULL); 
	hThread2=CreateThread(NULL,0,Fun2Proc,NULL,0,NULL); 
	cout<<"11111111111111111111111111111111\n";
	CloseHandle(hThread1); 
	CloseHandle(hThread2);
	//让主线程睡眠4秒 
	Sleep(4000);
	//关闭事件对象句柄 
	CloseHandle(g_hEvent);
}
//线程1的入口函数
DWORD WINAPI Fun1Proc(LPVOID lpParameter)//thread data
{
	while (true) {
		WaitForSingleObject(g_hEvent,INFINITE);
		//ResetEvent(g_hEvent);
		if (tickets>0) {
			Sleep(1); 
			cout<<"thread1 sell ticket :"<<tickets--<<endl;
			SetEvent(g_hEvent);
		} else { 
			SetEvent(g_hEvent);
			break; 
		}
	}
	return 0;
}

//线程2的入口函数
DWORD WINAPI Fun2Proc(LPVOID lpParameter)//thread data
{
	while (true) {
		//请求事件对象
		WaitForSingleObject(g_hEvent,INFINITE);
		//ResetEvent(g_hEvent);
		if (tickets>0) {
			Sleep(1);
			cout<<"thread2 sell ticket :"<<tickets--<<endl;
			SetEvent(g_hEvent);
		} else {
			SetEvent(g_hEvent);
			break; 
		} 
	}
	return 0;
}