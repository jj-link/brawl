#pragma force_active on
#include <types.h>

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_13_DC(void*);
void fn_13_894(void*);
void* fn_13_950(void*);
void fn_13_620(void*);
void loadMenuSound__6muMenuFv(void*);
void* readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void*, const char*, int, int, int);
int sprintf(char*, const char*, ...);
extern char lbl_13_data_0[];
extern char lbl_13_data_1C[];

void* fn_13_0(void) {
    char buf[0x40];
    char* p = (char*)__nw__FUlQ25Heaps8HeapType(0x198, 0x2a);
    if (p != 0) {
        p = (char*)fn_13_DC(p);
    }
    fn_13_894(p);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(p + 0xe8, lbl_13_data_0, 0x2b, 0, 0);
    int n = *(int*)(p + 0xb0);
    int idx = -1;
    if (n >= 2) {
        idx = n - 2;
    }
    void* menu;
    if (idx < 0) {
        menu = fn_13_950(p);
    } else {
        sprintf(buf, lbl_13_data_1C, idx + 1);
        menu = readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(p + 0xfc, buf, 0x2a, 0, 0);
    }
    loadMenuSound__6muMenuFv(menu);
    *(u8*)(p + 0x108) = 0;
    *(int*)(p + 0xe4) = 0;
    fn_13_620(p);
    return p;
}
}
