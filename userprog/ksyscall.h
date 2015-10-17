/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"

#include "synchconsole.h"


void SysHalt()
{
  kernel->interrupt->Halt();
}

int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysCreate(char *filename)
{
	// return value
	// 1: success
	// 0: failed
	return kernel->interrupt->CreateFile(filename);
}
void SysPrintInt(int val){
	kernel->interrupt->PrintInt(val);
}

OpenFile* SysOpen(char* filename){
	return kernel->Open_File(filename);			
}

int SysWrite(char *buffer, int size, OpenFile* openfile){
	return kernel->WriteFile(buffer,size,openfile);	

}
int SysRead(char *buffer, int size, OpenFile* openfile){
	return kernel->ReadFile(buffer,size,openfile);
}
int SysClose(OpenFile* openfile){
	return kernel->CloseFile(openfile);
}

#endif /* ! __USERPROG_KSYSCALL_H__ */
