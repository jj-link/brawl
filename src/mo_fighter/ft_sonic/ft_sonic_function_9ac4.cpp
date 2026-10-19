#include <types.h>

extern "C" void fn_27_13604C(void*);

struct Vt {
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void call(s32);
};

#pragma force_active on
extern "C" void fn_123_9AC4(void* self, void* unk, unsigned int kind) {
    fn_27_13604C(self);
    if (kind == 1) {
        u32 b = *(u32*)((u8*)*(u32**)((u8*)self + 0x60) + 0xd8);
        ((Vt*)*(u32*)(b + 0x64))->call(0x1200003D);
    }
}
