#pragma force_active on
typedef unsigned int u32;
typedef int s32;

class Obj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(s32 a, void* b);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual s32 slot16(void* mid);
    virtual u32 slot17(u32 id);
    virtual void slot18();
    virtual void slot19(u32 id);
};

struct Ctx {
    char pad0[0x64];
    Obj* p64;
    char pad1[0x70 - 0x68];
    Obj* p70;
};

struct Mid {
    char pad[0xd8];
    Ctx* ctx;
};

struct Self {
    char pad[0x60];
    Mid* mid;
};

extern "C" s32 fn_27_34C454(Self* self) {
    s32 result = 0;
    Mid* mid = self->mid;
    if (mid->ctx->p70->slot16(mid) == 1) {
        if (self->mid->ctx->p64->slot17(0x12000005) == 0) {
            if (self->mid->ctx->p64->slot17(0x12000006) == 1U) {
                self->mid->ctx->p70->slot3(2, self->mid);
                result = 1;
            }
        }
    }
    self->mid->ctx->p64->slot19(0x12000005);
    self->mid->ctx->p64->slot19(0x12000006);
    return result;
}
