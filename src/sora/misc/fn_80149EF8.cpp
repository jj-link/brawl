#include <nt/nt_send.h>
#include <revolution/OS/OSThread.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on
class BufferSlots { public: virtual void slot0(); virtual void slot1(); virtual void freeBuffer(); };
extern "C" {
extern unsigned char __vt__8NtBuffer[];
void __dl__FPv(void*);
extern char lbl_8045F7A8[];
extern NtSend* lbl_805A03D4;
void netReport__FPCce(const char*, ...);
}
extern "C" void fn_80149EF8(u8* self) {
    char* base = lbl_8045F7A8;
    if (self[0x11] == 0) return;
    if (lbl_805A03D4 != 0) {
        lbl_805A03D4->destroy();
        u8* s = (u8*)lbl_805A03D4;
        if (s != 0) {
            BufferSlots* b = (BufferSlots*)(s + 0x40);
            if (b != 0) {
                *(void**)(s + 0x40) = __vt__8NtBuffer;
                b->freeBuffer();
            }
            b = (BufferSlots*)(s + 0x24);
            if (b != 0) {
                *(void**)(s + 0x24) = __vt__8NtBuffer;
                b->freeBuffer();
            }
            __dl__FPv(s);
        }
        lbl_805A03D4 = 0;
    }
    if (self[0x33CD] == 0) {
        netReport__FPCce(base + 0xBB8);
        if (self[0x11] == 0) {
            self[0x33CD] = 1;
        } else if (self[0x33CC] == 0) {
            self[0x33CC] = 1;
            OSResumeThread((OSThread*)(self + 0xA0));
            netReport__FPCce(base + 0xB28);
        }
        while (self[0x33CD] == 0) {
            OSSleepTicks((s64)((OS_BUS_CLOCK_SPEED / 4) / 1000) * 16);
        }
        netReport__FPCce(base + 0xBF0);
    }
}