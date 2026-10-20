#pragma force_active on
typedef unsigned short u16;
typedef int s32;
typedef unsigned char u8;

struct Inner {
    u8 pad[0x1a];
    u16 code;
};

struct Outer {
    u8 pad[0x40];
    Inner* inner;
};

extern "C" {
extern s32 lbl_27_data_4DB80[];

s32 fn_27_2414B4(Outer* obj) {
    u16 v = obj->inner->code;
    if (v > 0x39) {
        return -1;
    }
    return lbl_27_data_4DB80[v];
}
}
