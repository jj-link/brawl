#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct fn41Inner {
    u32 unk0;
};

struct fn41Outer {
    fn41Inner* unk0;
    u8 unk4;
};

extern "C" {
int fn_41_A1C4(fn41Outer* p) {
    if (p->unk4 == 1) {
        return -1;
    }
    return p->unk0->unk0;
}
}
