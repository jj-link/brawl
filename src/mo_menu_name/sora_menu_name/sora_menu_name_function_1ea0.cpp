#pragma force_active on
typedef unsigned char u8;

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
u8* fn_16_1FC0(void*);
extern const char lbl_16_rodata_140[];
void fn_16_25A0(u8*, const void*, int, void*, int, void*);
void* fn_16_49F0(u8*, void*, void*);
void* fn_16_6C64(void*);
void fn_16_23D0(u8*, void*, int, void*, void*, void*, void*, void*, void*);
}

extern "C" u8* fn_16_1EA0(
    void* a0, int a1, int* a2, int* a3, void* a4, void* a5,
    void* a6, void* a7, void* s0, void* s1, void* s2, void* s3
) {
    u8* obj = (u8*)__nw__FUlQ25Heaps8HeapType(0x480, 0x2a);
    if (obj)
        obj = fn_16_1FC0(obj);

    *(int*)(obj + 0x40) = a2[0];
    *(int*)(obj + 0x44) = a2[1];
    *(int*)(obj + 0x48) = a2[2];
    *(int*)(obj + 0x4c) = a2[3];
    *(int*)(obj + 0x8c) = a3[0];
    *(int*)(obj + 0x90) = a3[1];
    obj[0x3f4] = 1;

    fn_16_25A0(obj, lbl_16_rodata_140, 8, a4, 0, a6);
    if (s1)
        *(void**)(obj + 0x408) = fn_16_6C64(fn_16_49F0(obj, s1, a6));

    fn_16_23D0(obj, a0, a1, a5, a6, a7, s0, s2, s3);
    return obj;
}
