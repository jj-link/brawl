#pragma force_active on
struct Inner {
    int unk0;
    int unk4;
    unsigned int mode : 3;
    unsigned int rest : 29;
};

struct Outer {
    int unk0;
    Inner *inner;
};

extern "C" void fn_27_B1C48(Outer *obj) {
    Inner *p = obj->inner;
    if (p == 0) {
        return;
    }
    p->mode = 1;
}
