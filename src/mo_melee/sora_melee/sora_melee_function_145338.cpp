#include <types.h>
#include <string.h>
#pragma force_active on

extern "C" {
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
void fn_27_6FEB8(void*, s32, s32, s32, s32, s32, s32, s32);
}

struct Bits33 {
    unsigned char hi : 7;
    unsigned char lo : 1;
};

extern "C" void fn_27_145338(
    void* self, const char* str, s32 arg2, u8 arg3, s32 arg4,
    u8 arg5, u8 arg6, s32 arg7, int heapType, u8 arg10,
    s32 arg11, u8 arg12
) {
    u8* p = (u8*)self;
    *(s32*)(p + 0x18) = arg2;
    p[0x30] = arg3;
    p[0x31] = arg5;
    p[0x32] = arg6;
    p[0x10] = arg10;
    *(s32*)(p + 0x24) = heapType;
    Bits33* bits = (Bits33*)(p + 0x33);
    bits->lo = (unsigned char)arg7;
    bits->hi = (unsigned char)arg4;
    *(s32*)(p + 0x2C) = arg11;

    if (str != 0) {
        s32 n = strlen(str) + 1;
        void* buf = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(
            heapType, (unsigned long)n
        );
        *(void**)(p + 0x28) = buf;
        strcpy((char*)buf, str);

        s32 flag = 0;
        switch (arg4) {
        case 6:
        case 7:
            switch (arg2) {
            case 3:
            case 5:
            case 11:
            case 13:
            case 14:
            case 24:
            case 29:
            case 30:
            case 31:
            case 48:
                flag = 1;
                break;
            }
            break;
        }
        fn_27_6FEB8(
            p + 0x1C, (s32)str, (s32)heapType, arg7,
            flag, (s32)arg12, 0x1F, 1
        );
    }
    p[0x08]++;
}
