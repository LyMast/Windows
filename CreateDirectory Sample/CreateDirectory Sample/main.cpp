
#include <iostream>
#include <Windows.h>

using namespace std;

int wmain(int argc, WCHAR* argv[])
{
	DWORD dwError;

	////////////////////////////////////////////////////////////////////
	// CreateDirectory - 생성 규칙 -
	//		1. IDE로 실행하면은 main.cpp 파일이 있는 곳에서 생성
	//		2. 실행파일로 시작하면 해당 실행파일이 있는 곳에서 디렉토리 생성
	// 
	// - 실패 - 
	//		- 해당 경로에 이미 같은 이름의 디렉토리가 있으면 실패한다.
	////////////////////////////////////////////////////////////////////
	BOOL bCreate = CreateDirectory(L"TestDirectory/", NULL);
	if (bCreate)
		wprintf(L"Created!\n\n");
	else
	{
		wprintf(L"Nope! : ");


		dwError = GetLastError();
		if (dwError == ERROR_ALREADY_EXISTS)	// 이미 존재
			wprintf(L"ERROR_ALREADY_EXISTS!\n\n");
		else if (dwError == ERROR_PATH_NOT_FOUND)	//
			wprintf(L"ERROR_PATH_NOT_FOUND!\n\n");
	}



	////////////////////////////////////////////////////////////////////
	//		첫 번째 Parameter에 PATH 지정 가능
	// 
	//		결과 : TestDirectory 하위 폴더로서 만들어진다.
	////////////////////////////////////////////////////////////////////
	bCreate = CreateDirectory(L"TestDirectory/InnerDirectory/", NULL);
	if (bCreate)
		wprintf(L"Created!\n\n");
	else
	{
		wprintf(L"Nope! : ");


		dwError = GetLastError();
		if (dwError == ERROR_ALREADY_EXISTS)	// 이미 존재
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
	//  첫 번째 파라미터 : 새 디렉터리를 만들 때 템플릿으로 사용할 디렉터리의 경로
	//  두 번째 파라미터 : 만들 디렉터리의 경로입니다.
	//  세 번째 파라미터 : 해당 디렉토리에 대한 보안 설명자.
	////////////////////////////////////////////////////////////////////
	BOOL bCreateEx = CreateDirectoryEx(L"./", L"Test2/", NULL);		// 성공
	if (bCreateEx)
		wprintf(L"Created!\n\n");
	else
	{
		wprintf(L"Nope! : ");


		dwError = GetLastError();
		if (dwError == ERROR_ALREADY_EXISTS)	// 이미 존재
			wprintf(L"ERROR_ALREADY_EXISTS!\n\n");
		else if (dwError == ERROR_PATH_NOT_FOUND)
			wprintf(L"ERROR_PATH_NOT_FOUND!\n\n");
	}

	//BOOL bCreateEx = CreateDirectoryEx(NULL, L"Test2", NULL);		// 실패 - ERROR_PATH_NOT_FOUND
	//BOOL bCreateEx = CreateDirectoryEx(L"", L"Test2", NULL);		// 실패 - ERROR_PATH_NOT_FOUND





	bCreateEx = CreateDirectoryEx(L"./Test2/", L"Test2Ex/", NULL);		// 성공	- 오류 : Test2 하위에 생긴것이 아니라 ./ 폴더안에 생성이 되었다.
	if (bCreateEx)
		wprintf(L"Created!\n\n");
	else
	{
		wprintf(L"Nope! : ");


		dwError = GetLastError();
		if (dwError == ERROR_ALREADY_EXISTS)	// 이미 존재
			wprintf(L"ERROR_ALREADY_EXISTS!\n\n");
		else if (dwError == ERROR_PATH_NOT_FOUND)
			wprintf(L"ERROR_PATH_NOT_FOUND!\n\n");
	}


	wstring Exit;
	wcout << L"Enter Anykey to Terminate : ";
	wcin >> Exit;

}













