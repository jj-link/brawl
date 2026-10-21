#pragma force_active on
typedef unsigned char u8;

struct Obj {
    int unk0;
    u8 unk4;
};

extern "C" {
void fn_802CDEC0(int unused, struct Obj* arg1) {
    arg1->unk0 = 8;
    arg1->unk4 = 1;
}
}
