/*
	sa0tour0 v2.25 by SKGleba
	All Rights Reserved
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>
#include <psp2/io/fcntl.h>
#include <psp2/io/stat.h>
#include "graphics.h"

char mmit[][150] = {" -> Change *.pvf fonts location"," -> Change *.pgf fonts location"," -> Change dictionary data location"," -> Change handwriting data location"};
char wmit[][150] = {" -> ur0:data/font/pvf/"," -> ux0:data/font/pvf/"," -> sa0:data/font/pvf/"," -> Back"};
char kmit[][150] = {" -> ur0:data/font/pgf/"," -> ux0:data/font/pgf/"," -> sa0:data/font/pgf/"," -> Back"};
char cmit[][150] = {" -> ur0:data/dic/utf16be/"," -> ux0:data/dic/utf16be/"," -> sa0:data/dic/utf16be/"," -> Back"};
char lmit[][150] = {" -> ur0:data/libhwr/"," -> ux0:data/libhwr/"," -> sa0:data/libhwr/"," -> Back"};
char rmit[][100] = {" -> ur0:data/"," -> ux0:data/"," -> sa0:data/"," -> Back"};
int optct = 4;

int sel = 0;
int i;
int shode = 0;

int fcp(const char *from, const char *to) {
	long fsz;
	FILE *fp = fopen(from,"rb");

	fseek(fp, 0, SEEK_END);
	fsz = ftell(fp);
	rewind(fp);

	char* fbuf = (char*) malloc(sizeof(char) * fsz);
	fread(fbuf, sizeof(char), (size_t)fsz, fp);

	FILE *pFile = fopen(to, "wb");
	
	for (int i = 0; i < fsz; ++i) {
			fputc(fbuf[i], pFile);
	}
   
	fclose(fp);
	fclose(pFile);
	return 1;
}

int ex(const char *fname) {
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

void smenu(){
	psvDebugScreenClear(COLOR_BLACK);
	psvDebugScreenSetFgColor(COLOR_GREEN);
	psvDebugScreenPrintf("                       sa0tour0 v2.25                            \n");
	psvDebugScreenPrintf("                         By SKGleba                              \n");
	psvDebugScreenPrintf("             Press SELECT to redirect everything                 \n");
	psvDebugScreenPrintf("                Press START to exit this app                     \n");
		psvDebugScreenSetFgColor(COLOR_RED);
	for(i = 0; i < optct; i++){
		if(sel==i){
			psvDebugScreenSetFgColor(COLOR_GREEN);
		}
		if (shode == 0) psvDebugScreenPrintf("%s\n", mmit[i]);
		if (shode == 1) psvDebugScreenPrintf("%s\n", wmit[i]);
		if (shode == 2) psvDebugScreenPrintf("%s\n", kmit[i]);
		if (shode == 3) psvDebugScreenPrintf("%s\n", cmit[i]);
		if (shode == 4) psvDebugScreenPrintf("%s\n", lmit[i]);
		if (shode == 5) psvDebugScreenPrintf("%s\n", rmit[i]);
		psvDebugScreenSetFgColor(COLOR_RED);
	}
	
	psvDebugScreenSetFgColor(COLOR_GREEN);
}

int do_shit(){
void *buf = malloc(0x100);
vshIoUmount(0x300, 0, 0, 0);
vshIoUmount(0x300, 1, 0, 0);
_vshIoMount(0x300, 0, 2, buf);
if (shode == 1){
psvDebugScreenPrintf("Working...\n");
if (ex("vs0:sys/external/pvf.o") == 0) fcp("vs0:sys/external/libpvf.suprx", "vs0:sys/external/pvf.o");
if (ex("vs0:sys/external/libpvf.suprx") == 1) sceIoRemove("vs0:sys/external/libpvf.suprx");
if (sel == 0) fcp("app0:Media/00", "vs0:sys/external/libpvf.suprx");
if (sel == 1) fcp("app0:Media/01", "vs0:sys/external/libpvf.suprx");
if (sel == 2) fcp("vs0:sys/external/pvf.o", "vs0:sys/external/libpvf.suprx");
psvDebugScreenPrintf("Done\n");
sceKernelDelayThread(1 * 1000 * 1000);sceKernelExitProcess(0);}
if (shode == 2){
psvDebugScreenPrintf("Working...\n");
if (ex("vs0:sys/external/pgf.o") == 0) fcp("vs0:sys/external/libpgf.suprx", "vs0:sys/external/pgf.o");
if (ex("vs0:sys/external/libpgf.suprx") == 1) sceIoRemove("vs0:sys/external/libpgf.suprx");
if (sel == 0) fcp("app0:Media/10", "vs0:sys/external/libpgf.suprx");
if (sel == 1) fcp("app0:Media/11", "vs0:sys/external/libpgf.suprx");
if (sel == 2) fcp("vs0:sys/external/pgf.o", "vs0:sys/external/libpgf.suprx");
psvDebugScreenPrintf("Done\n");
sceKernelDelayThread(1 * 1000 * 1000);sceKernelExitProcess(0);}
if (shode == 3){
psvDebugScreenPrintf("Working...\n");
if (ex("vs0:vsh/shell/ime.o") == 0) fcp("vs0:vsh/shell/ime_plugin.suprx", "vs0:vsh/shell/ime.o");
if (ex("vs0:vsh/shell/ime_plugin.suprx") == 1) sceIoRemove("vs0:vsh/shell/ime_plugin.suprx");
if (sel == 0) fcp("app0:Media/30", "vs0:vsh/shell/ime_plugin.suprx");
if (sel == 1) fcp("app0:Media/31", "vs0:vsh/shell/ime_plugin.suprx");
if (sel == 2) fcp("vs0:vsh/shell/ime.o", "vs0:vsh/shell/ime_plugin.suprx");
psvDebugScreenPrintf("Done\n");
sceKernelDelayThread(1 * 1000 * 1000);sceKernelExitProcess(0);}
if (shode == 4){
psvDebugScreenPrintf("Working...\n");
if (ex("vs0:sys/external/hwr.o") == 0) fcp("vs0:sys/external/libhandwriting.suprx", "vs0:sys/external/hwr.o");
if (ex("vs0:sys/external/libhandwriting.suprx") == 1) sceIoRemove("vs0:sys/external/libhandwriting.suprx");
if (sel == 0) fcp("app0:Media/20", "vs0:sys/external/libhandwriting.suprx");
if (sel == 1) fcp("app0:Media/21", "vs0:sys/external/libhandwriting.suprx");
if (sel == 2) fcp("vs0:sys/external/hwr.o", "vs0:sys/external/libhandwriting.suprx");
psvDebugScreenPrintf("Done\n");
sceKernelDelayThread(1 * 1000 * 1000);sceKernelExitProcess(0);}
if (shode == 5){
psvDebugScreenPrintf("Working...\n");
if (ex("vs0:sys/external/pvf.o") == 0) fcp("vs0:sys/external/libpvf.suprx", "vs0:sys/external/pvf.o");
if (ex("vs0:sys/external/pgf.o") == 0) fcp("vs0:sys/external/libpgf.suprx", "vs0:sys/external/pgf.o");
if (ex("vs0:vsh/shell/ime.o") == 0) fcp("vs0:vsh/shell/ime_plugin.suprx", "vs0:vsh/shell/ime.o");
if (ex("vs0:sys/external/hwr.o") == 0) fcp("vs0:sys/external/libhandwriting.suprx", "vs0:sys/external/hwr.o");
if (ex("vs0:sys/external/libpvf.suprx") == 1) sceIoRemove("vs0:sys/external/libpvf.suprx");
if (ex("vs0:sys/external/libpgf.suprx") == 1) sceIoRemove("vs0:sys/external/libpgf.suprx");
if (ex("vs0:sys/external/libhandwriting.suprx") == 1) sceIoRemove("vs0:sys/external/libhandwriting.suprx");
if (ex("vs0:vsh/shell/ime_plugin.suprx") == 1) sceIoRemove("vs0:vsh/shell/ime_plugin.suprx");
if (sel == 0){
fcp("app0:Media/00", "vs0:sys/external/libpvf.suprx");
fcp("app0:Media/10", "vs0:sys/external/libpgf.suprx");
fcp("app0:Media/20", "vs0:sys/external/libhandwriting.suprx");
fcp("app0:Media/30", "vs0:vsh/shell/ime_plugin.suprx");}
if (sel == 1){
fcp("app0:Media/01", "vs0:sys/external/libpvf.suprx");
fcp("app0:Media/11", "vs0:sys/external/libpgf.suprx");
fcp("app0:Media/21", "vs0:sys/external/libhandwriting.suprx");
fcp("app0:Media/31", "vs0:vsh/shell/ime_plugin.suprx");}
if (sel == 2){
fcp("vs0:sys/external/pvf.o", "vs0:sys/external/libpvf.suprx");
fcp("vs0:sys/external/pgf.o", "vs0:sys/external/libpgf.suprx");
fcp("vs0:sys/external/hwr.o", "vs0:sys/external/libhandwriting.suprx");
fcp("vs0:vsh/shell/ime.o", "vs0:vsh/shell/ime_plugin.suprx");}
psvDebugScreenPrintf("Done\n");
sceKernelDelayThread(1 * 1000 * 1000);sceKernelExitProcess(0);}}
int main()
{
	psvDebugScreenInit();
	psvDebugScreenClear(COLOR_BLACK);
	psvDebugScreenSetFgColor(COLOR_GREEN);
	SceCtrlData pad;
	
	int l = 1;// happens
	
	smenu();
		
	while (l == 1) {
			sceCtrlPeekBufferPositive(0, &pad, 1);

			if (pad.buttons == SCE_CTRL_CROSS) {
				switch (sel){

					case 0:
                        do_shit();
						if (shode == 0) shode = 1;
					break;
					case 1:
                        do_shit();
						if (shode == 0) shode = 2;
					break;
					case 2:
                        do_shit();
						if (shode == 0) shode = 3;
					break;
					case 3:
						if (shode == 0) shode = 4; else shode = 0;
					break;
				}
				sel = 0;
				smenu();
				sceKernelDelayThread(0.35 * 1000 * 1000);
			}
			
			if (pad.buttons == SCE_CTRL_UP) {
				if(sel!=0){
					sel--;
				}
				smenu();
				sceKernelDelayThread(0.3 * 1000 * 1000);
			}

			if (pad.buttons == SCE_CTRL_SELECT) {
				shode = 5;
				smenu();
				sceKernelDelayThread(0.3 * 1000 * 1000);
			}
			
			if (pad.buttons == SCE_CTRL_DOWN) {
				if(sel+1<optct){
					sel++;
				}
				smenu();
				sceKernelDelayThread(0.3 * 1000 * 1000);
			}
			if (pad.buttons == SCE_CTRL_START) sceKernelExitProcess(0);
	}
	
	sceKernelDelayThread(10 * 1000 * 1000);
	sceKernelExitProcess(0);
    return 0;
}
