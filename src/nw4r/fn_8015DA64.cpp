#pragma force_active on
typedef int s32;

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 v3();
    virtual s32 v4();
};

extern "C" s32 fn_8015DA64(Obj* self) {
    s32 a = self->v4();
    s32 b = self->v3();
    return b + a;
}
