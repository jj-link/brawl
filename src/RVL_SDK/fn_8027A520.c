#include <types.h>
#include <revolution/OS/OSAlarm.h>
#pragma force_active on

void fn_801CA7E8(void*);
void __dl__FPv(void*);

extern char lbl_80532188[];
extern char lbl_80532248[];

void* fn_8027A520(s32* arg0, s32 arg1) {
    s32* p;
    if (arg0 != 0) {
        OSCancelAlarm((OSAlarm*)(lbl_80532188 + *arg0 * 0x30));
        OSCancelAlarm((OSAlarm*)(lbl_80532248 + *arg0 * 0x30));
        p = (s32*)((char*)arg0 + 0x20);
        if (p != 0) {
            fn_801CA7E8(p);
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
