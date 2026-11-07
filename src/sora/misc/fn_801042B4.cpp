#pragma force_active on
#include <types.h>

extern "C" {
s32 fn_800FA740(void*);
void fn_800FA7B8(void*, s32, s32, void*, s32, void*, void*);
void fn_80101810(...);
void fn_80106208(void*);
void fn_801063BC(void);
s32 fn_801063C4(void);
void fn_8019D950(void*);
extern char lbl_8045CAF8[];
extern char lbl_8045CFCC[];
extern void* lbl_805A0310;
}

extern "C" void fn_801042B4(void* arg0, void** arg1) {
    char* self = (char*)arg0;
    char* base = (char*)lbl_805A0310;
    s32 var_r31 = 0;
    s32 var_r0;

    if (((*(u8*)(base + 0x42) >> 6) & 1) && fn_800FA740(*(void**)(base + 0x32C)) != 0) {
        fn_801063BC();
        if (fn_801063C4() != 0) {
            var_r31 = 1;
        }
    }
    if (var_r31 != 0) {
        var_r0 = 1;
    } else {
        fn_80101810(lbl_8045CAF8, *(void**)((char*)*(void**)((char*)*arg1 + 0xC) + 0x8));
        var_r0 = 0;
    }
    if (var_r0 != 0) {
        char* temp = *(char**)(self + 0x32C);
        void* temp_r31;
        void* temp_r3;
        fn_800FA7B8(temp, (s32)*(void**)((char*)*arg1 + 0x8), 1, temp + 0x3A4, 0x400, temp + 0x13A4, lbl_8045CFCC);
        temp_r31 = *arg1;
        *arg1 = 0;
        temp_r3 = *(void**)(self + 0x324);
        if (temp_r3 != 0) {
            fn_80106208(temp_r3);
        }
        *(void**)(self + 0x324) = temp_r31;
        temp_r3 = *(void**)(self + 0x2D4);
        if (temp_r3 != 0) {
            fn_8019D950(temp_r3);
        }
        temp_r3 = *(void**)(self + 0x318);
        if (temp_r3 != 0) {
            fn_8019D950(temp_r3);
        }
        *(s32*)(self + 0x320) = 2;
    }
}
