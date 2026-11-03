#include <types.h>
#pragma force_active on

extern void* fn_803974FC(void);
extern void* fn_80397564(void);
extern s32 fn_80397580(void* arg);
extern void* fn_80390044(s32 size, s32 type);
extern void fn_803900E4(void* arg0, s32 arg1);
extern void fn_80392738(void* dest, s32 count);
extern void* fn_803911C8(void* a, void* b, void* c, void* d, void* e, void* f, s32 g, s32 h);
extern void fn_803900A0(void* arg);
extern void fn_80396FFC(s32 arg0, void* arg1);
extern void fn_80397588(void* arg0, s32 arg1);

void* fn_80395CBC(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5) {
    void* ptr;
    void* x;
    void* b;
    s32 context;
    void* result;

    x = fn_803974FC();
    b = fn_80397564();
    context = fn_80397580(x);

    ptr = fn_80390044(0x8060, 0x20);
    if (ptr == NULL) {
        fn_803900E4(b, 1);
        return NULL;
    }

    fn_80392738(ptr, 0x8060);

    result = fn_803911C8(b, arg0, arg1, arg2, arg3, arg5, 0, 0);
    *(void**)((char*)ptr + 0x10) = result;
    if (result == NULL) {
        fn_803900A0(ptr);
        return NULL;
    }

    *(s32*)((char*)ptr + 0x14) = *(s32*)((char*)result + 0x2C);
    *(s32*)((char*)ptr + 0x00) = 0;
    *(s32*)((char*)ptr + 0x1C) = (s32)arg4;
    *(s32*)((char*)ptr + 0x24) = 0;
    *(s32*)((char*)ptr + 0x28) = 0;
    *(s32*)((char*)ptr + 0x18) = -1;
    fn_80396FFC(context, ptr);
    *(s32*)((char*)ptr + 0x04) = 0xF;
    *(s32*)((char*)ptr + 0x08) = 0;
    *(s32*)((char*)ptr + 0x0C) = 1;
    fn_80397588(ptr, 0);
    *(s32*)((char*)ptr + 0x30) = 0;
    *(s32*)((char*)ptr + 0x8040) = 0;
    *(s32*)((char*)ptr + 0x8044) = 0;
    fn_80392738((char*)ptr + 0x40, 0x8000);
    return ptr;
}