#include <types.h>
#pragma force_active on

extern "C" {
extern const u8 lbl_27_data_71EB8[];
extern s32 lbl_27_data_71BF0[];
extern s32 lbl_27_rodata_47C8[];
}

struct Item {
    u8 pad0[8];
    s32 unk8;
    s32 unkC;
};

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual Item** get(s32 index);
    virtual s32 count();
};

extern "C" {
Item* fn_27_2A59C0(void* self, s32 arg1, s32 arg2) {
    u8* base = (u8*)self;
    s32 key;
    s32 want;
    s32 i;
    s32 r0 = 0;
    s32 c;
    u8 t;

    if (arg1 > -1 && arg1 < 0xB2) r0 = 1;
    if (r0 == 0) key = 0;
    else if (arg2 == 0x1388) key = 0x1388;
    else key = arg2 & ~(lbl_27_rodata_47C8[arg1] >> 31);

    want = arg1;
    if (base[0x14A0] == 0) goto adc;
    if (arg1 == -3) {
        arg1 = -1;
        goto ae0;
    }
    if (arg1 < 0 || arg1 >= 0xB2) t = 0;
    else t = lbl_27_data_71EB8[arg1];
    if (t == 0) {
        arg1 = -1;
        goto ae0;
    }
    if (arg1 == -3) c = 1;
    else if (arg1 < 0 || arg1 >= 0xB2) c = -1;
    else c = lbl_27_data_71BF0[arg1];
    switch (c) {
    case 1:
    case 6:
    case 7:
        goto ae0;
    }
adc:
    arg1 = -1;
ae0:
    if (arg1 >= 0) want = -3;

    for (i = 0; i < ((Inner*)(base + 0xC8))->count(); i++) {
        Item** p = ((Inner*)(base + 0xC8))->get(i);
        if (*p != 0 && want == (*p)->unk8 && key == (*p)->unkC) return *p;
    }
    return 0;
}
}