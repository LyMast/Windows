
#include <iostream>
#include <Windows.h>

using namespace std;

int wmain(int argc, WCHAR* argv[])
{
	DWORD dwError;

	////////////////////////////////////////////////////////////////////
	// CreateDirectory - ���� ��Ģ -
	//		1. IDE�� �����ϸ��� main.cpp ������ �ִ� ������ ����
	//		2. �������Ϸ� �����ϸ� �ش� ���������� �ִ� ������ ���丮 ����
	// 
	// - ���� - 
	//		- �ش� ��ο� �̹� ���� �̸��� ���丮�� ������ �����Ѵ�.
	////////////////////////////////////////////////////////////////////
	BOOL bCreate = CreateDirectory(L"TestDirectory/", NULL);
	if (bCreate)
		wprintf(L"Created!\n\n");
	else
	{
		wprintf(L"Nope! : ");


		dwError = GetLastError();
		if (dwError == ERROR_ALREADY_EXISTS)	// �̹� ����
			wprintf(L"ERROR_ALREADY_EXISTS!\n\n");
		else if (dwError == ERROR_PATH_NOT_FOUND)	//
			wprintf(L"ERROR_PATH_NOT_FOUND!\n\n");
	}



	////////////////////////////////////////////////////////////////////
	//		ù ��° Parameter�� PATH ���� ����
	// 
	//		��� : TestDirectory ���� �����μ� ���������.
	////////////////////////////////////////////////////////////////////
	bCreate = CreateDirectory(L"TestDirectory/InnerDirectory/", NULL);
	if (bCreate)
		wprintf(L"Created!\n\n");
	else
	{
		wprintf(L"Nope! : ");


		dwError = GetLastError();
		if (dwError == ERROR_ALREADY_EXISTS)	// �̹� ����
			wprintf(L"ERROR_ALREADY_EXISTS!\n\n");
		else if (dwError == ERROR_PATH_NOT_FOUND)
			wprintf(L"ERROR_PATH_NOT_FOUND!\n\n");
	}




	////////////////////////////////////////////////////////////////////
	// CreateDirectoryEx 
	// 
	//		Reference : https://learn.microsoft.com/ko-kr/windows/win32/api/winbase/nf-winbase-createdirectoryexa
	//		Naming File Ref : https://learn.microsoft.com/ko-kr/windows/win32/fileio/naming-a-file
	// 
	//  ù ��° �Ķ���� : �� ���͸��� ���� �� ���ø����� ����� ���͸��� ���
	//  �� ��° �Ķ���� : ���� ���͸��� ����Դϴ�.
	//  �� ��° �Ķ���� : �ش� ���丮�� ���� ���� ������.
	////////////////////////////////////////////////////////////////////
	BOOL bCreateEx = CreateDirectoryEx(L"./", L"Test2/", NULL);		// ����
	if (bCreateEx)
		wprintf(L"Created!\n\n");
	else
	{
		wprintf(L"Nope! : ");


		dwError = GetLastError();
		if (dwError == ERROR_ALREADY_EXISTS)	// �̹� ����
			wprintf(L"ERROR_ALREADY_EXISTS!\n\n");
		else if (dwError == ERROR_PATH_NOT_FOUND)
			wprintf(L"ERROR_PATH_NOT_FOUND!\n\n");
	}

	//BOOL bCreateEx = CreateDirectoryEx(NULL, L"Test2", NULL);		// ���� - ERROR_PATH_NOT_FOUND
	//BOOL bCreateEx = CreateDirectoryEx(L"", L"Test2", NULL);		// ���� - ERROR_PATH_NOT_FOUND





	bCreateEx = CreateDirectoryEx(L"./Test2/", L"Test2Ex/", NULL);		// ����	- ���� : Test2 ������ ������� �ƴ϶� ./ �����ȿ� ������ �Ǿ���.
	if (bCreateEx)
		wprintf(L"Created!\n\n");
	else
	{
		wprintf(L"Nope! : ");


		dwError = GetLastError();
		if (dwError == ERROR_ALREADY_EXISTS)	// �̹� ����
			wprintf(L"ERROR_ALREADY_EXISTS!\n\n");
		else if (dwError == ERROR_PATH_NOT_FOUND)
			wprintf(L"ERROR_PATH_NOT_FOUND!\n\n");
	}


	wstring Exit;
	wcout << L"Enter Anykey to Terminate : ";
	wcin >> Exit;

}













