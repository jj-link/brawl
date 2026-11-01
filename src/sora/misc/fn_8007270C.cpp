#include <gf/gf_heap_manager.h>
#pragma force_active on

extern "C" {
void free__13gfHeapManagerFPv(void*);
int fn_801F270C(unsigned short, unsigned short, void*, int, int);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(void*, int, unsigned long);
void fn_801D76BC(void*, unsigned int);
void fn_801F1564(unsigned short, unsigned short, unsigned short, unsigned short);
void fn_801F15C8(unsigned short, unsigned short, void*, unsigned char);
void fn_801F1E60(void*, unsigned char);
void fn_801F28F0(void*, unsigned int, unsigned short, unsigned short, unsigned int, unsigned int, unsigned int, unsigned char);
void fn_801F2B44(void*, int, int, int, int, int, float, float, float);
extern const float lbl_805A1AC0;

int fn_8007270C(void* arg0, void* arg1, gfHeapManager* arg2, unsigned char arg3,
                float x1, float y1, float x2, float y2) {
    unsigned char* p = (unsigned char*)arg0;

    if (*(void**)(p + 0x24) != 0) {
        free__13gfHeapManagerFPv(*(void**)(p + 0x24));
        *(void**)(p + 0x24) = 0;
        *(int*)(p + 0x28) = 0;
        *(int*)(p + 0x38) = 0;
        *(int*)(p + 0x34) = 0;
        *(int*)(p + 0x30) = 0;
        *(int*)(p + 0x2C) = 0;
    }

    *(unsigned char*)(p + 0x40) = 0;
    *(void**)(p + 0x3C) = arg1;
    *(int*)(p + 0x2C) = (int)y1;
    *(int*)(p + 0x30) = (int)x1;
    *(int*)(p + 0x34) = (int)(x2 - x1);
    *(int*)(p + 0x38) = (int)(y2 - y1);
    *(unsigned char*)(p + 0x41) = arg3;

    int type = fn_801F270C((unsigned short)*(int*)(p + 0x34),
                           (unsigned short)*(int*)(p + 0x38),
                           arg1, 0, 0);
    *(void**)(p + 0x24) =
        alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(arg2, type, 0x20);
    *(int*)(p + 0x28) = type;
    fn_801D76BC(*(void**)(p + 0x24), (unsigned int)type);

    int width = (unsigned short)*(int*)(p + 0x34);
    unsigned short height = (unsigned short)*(int*)(p + 0x38);
    if (*(unsigned char*)(p + 0x40)) {
        width = width >> 1;
        height = (unsigned short)((height >> 1) & 0x7FFF);
    }

    fn_801F1564((unsigned short)*(int*)(p + 0x30),
                (unsigned short)*(int*)(p + 0x2C),
                (unsigned short)*(int*)(p + 0x34),
                (unsigned short)*(int*)(p + 0x38));
    fn_801F15C8((unsigned short)width, height, *(void**)(p + 0x3C),
                *(unsigned char*)(p + 0x40));
    fn_801F1E60(*(void**)(p + 0x24), *(unsigned char*)(p + 0x41));
    fn_801F28F0(p + 4, (unsigned int)*(void**)(p + 0x24),
                (unsigned short)width, height,
                (unsigned int)*(void**)(p + 0x3C), 0, 0, 0);
    fn_801F2B44(p + 4, 1, 1, 0, 0, 0,
                lbl_805A1AC0, lbl_805A1AC0, lbl_805A1AC0);
    return 1;
}
}
