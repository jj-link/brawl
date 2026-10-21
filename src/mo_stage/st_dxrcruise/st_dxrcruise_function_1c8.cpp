#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_80_data_24C[];
extern void* lbl_805A0360;
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__13grTenganEventFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_80_1C8(void* p, int flag) {
    if (p != 0) {
        *(void**)((char*)p + 0x3C) = lbl_80_data_24C;
        unsigned char* bits = (unsigned char*)lbl_805A0360 + 0x40;
        *bits &= ~0x20u;
        releaseArchive__15stCommonGimmickFv(p);
        __destroy_arr((char*)p + 0xDCC, __dt__13grTenganEventFv, 0xAC, 3);
        __destroy_arr((char*)p + 0x1D8, __dt__13grTenganEventFv, 0xAC, 0x11);
        __dt__7stMeleeFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
