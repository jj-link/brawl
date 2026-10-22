#pragma force_active on
struct Sub {
    int x;
};

struct Obj {
    unsigned char padding[0x6EF];
    unsigned char active;
    unsigned char padding2[0x38];
    Sub sub;
};

struct SrcData {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
};

extern "C" SrcData* fn_801C07AC(Sub*);
extern "C" void fn_801C05C0(Sub*, SrcData*, int);

extern "C" void fn_80077604(Obj* self, float deltaFrame) {
    if (self->active) {
        SrcData* p = fn_801C07AC(&self->sub);
        SrcData local = *p;
        *(float*)&local.fC = deltaFrame;
        fn_801C05C0(&self->sub, &local, local.f10);
    }
}
