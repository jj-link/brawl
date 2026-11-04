#include <mv/mv_THPPlayer.h>
#include <mv/mv_THPRead.h>
#include <mv/mv_THPAudioDecode.h>
#include <revolution/OS/OSMessage.h>
#pragma force_active on

extern "C" void fn_8007E944(OSMessage);
extern char* lbl_805A01F8;

extern "C" void fn_8007C538() {
    int i;
    char* p;
    if (*(int*)((char*)&g_thpObject + 0xB0) == 0) {
        p = (char*)&g_thpObject + 0xF0;
        i = 0;
        do {
            PushFreeReadBuffer(p);
            i++;
            p += 0xC;
        } while (i < 6);
    }
    i = 0;
    p = (char*)&g_thpObject + 0x138;
    do {
        fn_8007E944(p);
        i++;
        p += 0x10;
    } while (i < 3);
    if (g_thpObject.unkA7[0] != 0) {
        p = (char*)&g_thpObject + 0x168;
        i = 0;
        do {
            PushFreeAudioBuffer(p);
            i++;
            p += 0xC;
        } while (i < 6);
    }
    OSInitMessageQueue((OSMessageQueue*)(lbl_805A01F8 + 0x7A0), (OSMessage*)(lbl_805A01F8 + 0x7E0), 2);
}