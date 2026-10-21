#pragma force_active on
#include <types.h>

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(u32 arg);
};

struct Mod {
    char pad[0x64];
    Inner* unk64;
};

struct Acc {
    char pad[0xD8];
    Mod* unkD8;
};

class Self {
public:
    virtual void v0();
    virtual void v1(Acc* acc);
    unsigned char unk4;
    unsigned char f5a : 1;
    unsigned char f5b : 7;
    unsigned char f6;
    char pad7[9];
    float f10;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Acc* acc, u32 a, u32 b);

extern "C" void fn_27_3BD860(Self* self, u32 unused, Acc* acc) {
    Mod* mod = acc->unkD8;
    Inner* inner = mod->unk64;
    if (inner->v4(0x20000002) == 0) {
        self->f10 = -getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xBCF, 0);
    }
    if ((u32)(!!self->f5a) == 1 && self->f6 == 0) {
        self->v1(acc);
    }
}
