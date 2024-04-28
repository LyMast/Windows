
//*
#include <iostream>
#include <Windows.h>
#include <process.h>

using namespace std;

#define df_VAR_COUNT	10000000
HANDLE g_hEvent;


int g_iVar = 0;
unsigned __stdcall TestThread(void* pParam);
//unsigned __stdcall TestFiberThread(void* pParam);
VOID WINAPI FiberFunc(void* pParam);



int wmain(int argc, WCHAR* argv[])
{
	HANDLE hThread = NULL;

	g_hEvent = CreateEvent(0, TRUE, 0, 0);
	if (g_hEvent == NULL)
	{

		return -1;
	}

	hThread = (HANDLE)_beginthreadex(0, 0, TestThread, 0, 0, 0);
	if (hThread == NULL)
	{

		return -1;
	}

	SetEvent(g_hEvent);
	WaitForSingleObject(hThread, INFINITE);


	cout << g_iVar << endl;


	return 0;
}

unsigned __stdcall TestThread(void* pParam)
{
	PVOID param = ConvertThreadToFiberEx(NULL, FIBER_FLAG_FLOAT_SWITCH);

	LPFIBER_START_ROUTINE;

	PVOID param2 = CreateFiberEx(0, 0, FIBER_FLAG_FLOAT_SWITCH, FiberFunc, param);
	PVOID param3 = CreateFiberEx(0, 0, FIBER_FLAG_FLOAT_SWITCH, FiberFunc, param);

	SwitchToFiber(param2);
	SwitchToFiber(param3);

	cout << "end\n";

	return 0;
}

VOID WINAPI FiberFunc(void* pParam)
{

	WaitForSingleObject(g_hEvent, INFINITE);

	for (int i = 0; i < df_VAR_COUNT; ++i)
		g_iVar += 1;

	g_iVar += 1;

	if (pParam != 0)
		SwitchToFiber(pParam);


	return;
}

//*/
