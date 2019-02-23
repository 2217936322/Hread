#pragma once
#include <NtAPI.h>
#include <SSDT.h>
#define THREAD_MAX_NUMBER 0x300
#define SSDT_OPEN_THREAD 295
#define SSDT_NTSUSPENDTHRED 436
#define SSDT_RESUMETHREAD   82
namespace FastFunction
{

	ULONG64 GetSystemModuleBase(char* lpModuleName);

	VOID GetSystemModuleBase(char* lpModuleName, ULONG64 *ByRefBase, ULONG *ByRefSize);

	NTSTATUS HideDriver(char *pDrvName,PDRIVER_OBJECT pPDriverObj);

	PVOID RvaToVaHades(_In_ PVOID pModuleBase, _In_ ULONG Rva);

	PVOID GetModuleExport(_In_ PVOID pModuleBase, _In_ PCHAR pExportName);

	PVOID GetModuleBaseWow64(_In_ PEPROCESS pEProcess, _In_ PWCHAR pModuleName);

	PEPROCESS GetProcessPeprocess(int Pid);

	PVOID GetFunctionFromModule(_In_ PEPROCESS pEProcess, _In_ PWCHAR DllName, _In_ PCHAR FunctionName, BOOLEAN IsAttach);

	char* GetProcessNamebyHandle(HANDLE handle);

	NTSTATUS ApcpQuerySystemProcessInformation(PSYSTEM_PROCESS_INFO * SystemInfo);
	/*
	   ��ȡ�������̵߳�ET�ṹ
	   ����1:����PID
	   ����2:�߳��� 
	   ����3:��¼�߳�Tid�����顣
	   ����4���߳���ʼ��ַ
	*/
	NTSTATUS GetProcessThreadInfo(IN ULONG Pid,OUT ULONG *ThreadNuber,OUT PULONG64 Tid, OUT PULONG64 StartAddr);



	HANDLE OpenThread(DWORD dwDesiredAccess, BOOL  bInheritHandle, DWORD dwThreadId);

	NTSTATUS SuspendThread(__in HANDLE ThreadHandle);

	NTSTATUS ResumeThread(HANDLE hThread);
	
	NTSTATUS GetDriverThread(char *DriverName, OUT ULONG *ThreadNuber, OUT PULONG64 Tid);

}