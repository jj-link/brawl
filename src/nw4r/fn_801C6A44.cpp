#pragma force_active on
struct Obj {
    int unk0;
    int unk4;
    unsigned char unk8;
    unsigned char unk9;
};

extern "C" {
Obj* fn_801C0A0C(char* p);

Obj* fn_801C6A44(char* p, unsigned int n) {
    if (n != 0x18) {
        return 0;
    }
    Obj* o = fn_801C0A0C(p + 8);
    if (o == 0) {
        return 0;
    }
    if (o != 0) {
        o->unk0 = -1;
        o->unk4 = 0;
        o->unk8 = 1;
        o->unk9 = 0x80;
    }
    return o;
}
}
