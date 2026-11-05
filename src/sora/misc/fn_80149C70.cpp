#include <nt/nt_send.h>
#include <revolution/OS/OSThread.h>
#include <string.h>
#pragma force_active on
class BufferDispatch { public: virtual void f0(); virtual void alloc(unsigned int, Heaps::HeapType); };
extern "C" {
void fn_80146FCC(int);
void fn_801473AC();
void* fn_8014B364(void*);
extern int lbl_805A03E0, lbl_805A03E8, lbl_805A03F4;
extern unsigned char lbl_805A03E4, lbl_805A0438;
extern OSMutex lbl_8049EC78, lbl_8049EC30, lbl_8049EC48;
extern NtSend* lbl_805A03D4;
extern unsigned char __vt__8NtBuffer[];
void* __nw__FUlQ25Heaps8HeapType(unsigned int, Heaps::HeapType);
}
extern "C" void fn_80149C70(unsigned char* self, int arg1) {
    fn_80146FCC(0);
    lbl_805A03E0 = 0;
    self[0x33ce] = 0;
    *(int*)(self+0x94) = 0;
    *(int*)(self+0x98) = 0;
    lbl_805A03E4 = 0;
    self[0x33cc] = 0;
    lbl_805A0438 = 0;
    *(int*)(self+0x3444) = 0;
    *(int*)(self+0x3440) = 0;
    *(int*)(self+0x3408) = 0;
    *(int*)(self+0x3448) = 0;
    self[0x343c] = 0;
    self[0x33f4] = 0;
    self[0x33f5] = 0;
    self[0x33f6] = 0;
    *(int*)(self+0x340c) = 0;
    self[0x3410] = 0;
    self[0x3411] = 0;
    *(int*)(self+0x341c) = 0;
    *(int*)(self+0x3418) = 0;
    *(signed char*)(self+0x3420) = -1;
    *(signed char*)(self+0x3421) = -1;
    *(int*)(self+0x3494) = 100;
    *(int*)(self+0x349c) = 0;
    *(int*)(self+0x34a0) = 0;
    *(int*)(self+0x3428) = 0;
    *(int*)(self+0x342c) = 0;
    *(int*)(self+0x34a4) = 0;
    *(int*)(self+0x3430) = 0;
    *(int*)(self+0x3434) = 0;
    int v;
    switch (lbl_805A03F4) {
    case 2: case 3: case 4: case 5: case 6: case 7: v = 1; break;
    default: v = 0; break;
    }
    if (v == 0) {
        int w;
        switch (lbl_805A03E8) {
        case 7: {
            int u;
            switch (lbl_805A03F4) {
            case 2: case 3: case 4: case 5: case 6: case 7: u = 1; break;
            default: u = 0; break;
            }
            if (u == 0) goto L;
            w = 1; break;
        }
        case 2: case 3: case 6: case 14: w = 1; break;
        default:
        L: w = 0; break;
        }
        if (w == 0) fn_801473AC();
    }
    ((BufferDispatch*)(self+0x33b8))->alloc(0x8000, (Heaps::HeapType)6);
    OSInitMutex(&lbl_8049EC78);
    OSInitMutex(&lbl_8049EC30);
    OSInitMutex(&lbl_8049EC48);
    if (arg1 != 0) {
        memset(self+0x3b8, 0x55, 0x3000);
        memset(self+0xa0, 0, 0x318);
        OSCreateThread((OSThread*)(self+0xa0), fn_8014B364, 0, self+0x33b8, 0x3000, 11, 1);
        OSResumeThread((OSThread*)(self+0xa0));
        self[0x11] = 1;
        self[0x33cd] = 0;
    }
    unsigned char* p = (unsigned char*)__nw__FUlQ25Heaps8HeapType(0x54, (Heaps::HeapType)6);
    if (p) {
        *(void**)(p+0x24) = __vt__8NtBuffer;
        *(int*)(p+0x28) = 0;
        *(int*)(p+0x2c) = 0;
        p[0x30] = 0;
        *(int*)(p+0x34) = 0;
        *(void**)(p+0x40) = __vt__8NtBuffer;
        *(int*)(p+0x44) = 0;
        *(int*)(p+0x48) = 0;
        p[0x4c] = 0;
        *(int*)(p+0x50) = 0;
    }
    lbl_805A03D4 = (NtSend*)p;
    lbl_805A03D4->create();
    memset(self+0x12, 0, 0x40);
    memset(self+0x52, 0, 0x40);
}