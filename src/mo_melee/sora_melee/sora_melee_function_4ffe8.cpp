#include <types.h>
#pragma force_active on

struct Entry {
    s32 a;
    s32 b;
    u8 pad8;
    u8 c;
    u8 pad10[2];
};

extern "C" Entry lbl_27_data_4B00[11];
extern "C" void fn_27_36FE0(void*, void*, u8);
extern "C" void* fn_8015C1B0(void*, void*);

extern "C" void fn_27_4FFE8(s32 arg0) {
    for (int i = 0; i < 11; ++i) {
        Entry* e = &lbl_27_data_4B00[i];
        s32 a = e->a;
        s32 b = e->b;
        u8 c = e->c;
        void* listA = (void*)(arg0 + a * 12 + 0x40);
        void* listB = (void*)(arg0 + b * 12 + 0x40);
        void* nodeA = 0;
        void* nodeB;
        while ((nodeA = fn_8015C1B0(listA, nodeA)) != 0) {
            nodeB = (a == b) ? nodeA : 0;
            while ((nodeB = fn_8015C1B0(listB, nodeB)) != 0) {
                fn_27_36FE0(nodeA, nodeB, c);
            }
        }
    }
}
