#pragma force_active on
#include <types.h>
#include <gf/gf_task.h>
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);
extern char lbl_80420840[];
extern char lbl_8042084C[];
extern gfTask* lbl_8059FF90;
extern const f32 lbl_805A13A8;
extern const f32 lbl_805A13AC;

void fn_80011C74(s32 heapType) {
    char* p = (char*)__nw__FUlQ25Heaps8HeapType(0x78, heapType);
    if (p != 0) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(p, lbl_80420840, 0, 2, 6, true);
        *(char**)(p + 0x3C) = lbl_8042084C;
        *(f32*)(p + 0x40) = lbl_805A13A8;
        *(f32*)(p + 0x44) = lbl_805A13AC;
        *(f32*)(p + 0x48) = lbl_805A13A8;
        *(f32*)(p + 0x4C) = lbl_805A13AC;
        p[0x50] = 0;
        p[0x51] |= 0x80;
        *(int*)(p + 0x54) = 0;
        u32* z = (u32*)((u32)p + 0x6C);
        char* q = (char*)((u32)p + 0x6C);
        z[0] = 0;
        z[1] = 0;
        *(int*)(p + 0x68) = 0;
        *(char**)(p + 0x6C) = q;
        *(char**)(p + 0x70) = q;
        *(int*)(p + 0x58) = 0;
        *(int*)(p + 0x5C) = 0;
        *(int*)(p + 0x60) = 0;
        *(int*)(p + 0x64) = 0;
        p[0x74] = 0;
        p[0x75] = 0;
    }
    lbl_8059FF90 = (gfTask*)p;
}
}
