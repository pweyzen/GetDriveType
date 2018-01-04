// GetDriveType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>

int main()
{
	// Buffer length

	DWORD mydrives = 10240;
	char lpBuffer[10240];
	DWORD test;
	int i;
	test = GetLogicalDriveStringsA(mydrives, (LPSTR)lpBuffer);

	if (test != 0)
	{
		printf("GetLogicalDriveStrings() return value: %d, Error (if any): %d \n", test, GetLastError());
		printf("The logical drives of this machine are:\n");

		int idx = 0;
		while ( lpBuffer[idx] != NULL )
		{ 
			char * driveStringBuf = &lpBuffer[idx];

			switch (GetDriveTypeA(driveStringBuf))
			{
			case DRIVE_UNKNOWN:
				printf("%s: DRIVE_UNKNOWN\n", driveStringBuf );
				break;
			case DRIVE_NO_ROOT_DIR:
				printf("%s: DRIVE_NO_ROOT_DIR\n", driveStringBuf);
				break;
			case DRIVE_REMOVABLE:
				printf("%s: DRIVE_REMOVABLE\n", driveStringBuf);
				break;
			case DRIVE_FIXED:
				printf("%s: DRIVE_FIXED\n", driveStringBuf);
				break;
			case DRIVE_REMOTE:
				printf("%s: DRIVE_REMOTE\n", driveStringBuf);
				break;
			case DRIVE_CDROM:
				printf("%s: DRIVE_CDROM\n", driveStringBuf);
				break;
			case DRIVE_RAMDISK:
				printf("%s: DRIVE_RAMDISK\n", driveStringBuf);
				break;
			}
			idx += lstrlen(driveStringBuf) + 1;
		}
		printf("\n");
	}
	else
	{
		printf("GetLogicalDriveStrings() is failed lor!!! Error code: %d\n", GetLastError());
	}
	return 0;
}

