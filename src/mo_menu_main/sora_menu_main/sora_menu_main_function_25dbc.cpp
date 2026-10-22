#include <types.h>
#pragma force_active on

extern "C" {
void fn_18_11C4(void*, void*, void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern unsigned char lbl_2_data_3030[];
extern unsigned char lbl_2_data_3150[];
extern unsigned char lbl_2_data_32E0[];
extern unsigned char lbl_2_data_3580[];
extern unsigned char lbl_2_data_34F0[];
}

extern "C" void* fn_2_25DBC(void* self, void* arg2, void* arg3, void* arg6) {
    u8* s = (u8*)self;
    fn_18_11C4(self, arg2, arg3);
    *(u16*)(s + 0x640) = 0;
    *(void**)(s + 0x668) = lbl_2_data_3030;
    *(void**)(s + 0x694) = arg6;

    void* p1 = __nw__FUlQ25Heaps8HeapType(0x680, 0x2A);
    if (p1) {
        fn_18_11C4(p1, *(void**)(s + 0x64C), *(void**)(s + 0x650));
        *(u16*)((u8*)p1 + 0x640) = 0;
        *(void**)((u8*)p1 + 0x668) = lbl_2_data_3150;
    }
    *(void**)(s + 0x680) = p1;

    void* p2 = __nw__FUlQ25Heaps8HeapType(0x684, 0x2A);
    if (p2) {
        fn_18_11C4(p2, *(void**)(s + 0x64C), *(void**)(s + 0x650));
        *(u16*)((u8*)p2 + 0x640) = 0;
        *(void**)((u8*)p2 + 0x668) = lbl_2_data_32E0;
    }
    *(void**)(s + 0x684) = p2;

    void* p3 = __nw__FUlQ25Heaps8HeapType(0x6A8, 0x2A);
    if (p3) {
        fn_18_11C4(p3, *(void**)(s + 0x64C), *(void**)(s + 0x650));
        *(u16*)((u8*)p3 + 0x640) = 0;
        *(void**)((u8*)p3 + 0x668) = lbl_2_data_3580;
    }
    *(void**)(s + 0x688) = p3;

    void* p4 = __nw__FUlQ25Heaps8HeapType(0x6C0, 0x2A);
    if (p4) {
        fn_18_11C4(p4, *(void**)(s + 0x64C), *(void**)(s + 0x650));
        *(u16*)((u8*)p4 + 0x640) = 0;
        *(void**)((u8*)p4 + 0x668) = lbl_2_data_34F0;
    }
    *(void**)(s + 0x68C) = p4;

    return self;
}
