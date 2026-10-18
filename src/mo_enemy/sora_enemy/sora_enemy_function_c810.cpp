#include <types.h>
#pragma force_active on

struct Unk18 {
    u8 data[0x18];
};

extern "C" void fn_41_C8D0(Unk18*);
extern "C" u8 lbl_41_data_1638[];

extern "C" void* fn_41_C810(void* self, u32 count1, Unk18* array1,
                            u32 count2, Unk18* array2, u8 flag) {
    u32 i;

    *(u8**)((u8*)self + 0x1C) = lbl_41_data_1638;
    *(u32*)((u8*)self + 0x00) = count1;
    *(Unk18**)((u8*)self + 0x04) = array1;

    for (i = 0; i < *(u32*)((u8*)self + 0x00); ++i) {
        fn_41_C8D0((Unk18*)((u8*)*(Unk18**)((u8*)self + 0x04) + i * 0x18));
    }

    *(u32*)((u8*)self + 0x08) = 0;
    *(u32*)((u8*)self + 0x0C) = count2;
    *(Unk18**)((u8*)self + 0x10) = array2;

    for (i = 0; i < *(u32*)((u8*)self + 0x0C); ++i) {
        fn_41_C8D0((Unk18*)((u8*)*(Unk18**)((u8*)self + 0x10) + i * 0x18));
    }

    *(u32*)((u8*)self + 0x14) = 0;
    *(u8*)((u8*)self + 0x18) = flag;

    return self;
}
