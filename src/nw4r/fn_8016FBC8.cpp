#pragma force_active on
typedef unsigned int u32;

struct Inner {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

struct Outer {
    u32 unk0;
    Inner* unk4;
};

extern "C" {
int fn_8016FBC8(Outer* p) {
    Inner* temp = p->unk4;
    if (temp == 0) {
        return 0;
    }
    return p->unk0 == temp->unk8;
}
}
