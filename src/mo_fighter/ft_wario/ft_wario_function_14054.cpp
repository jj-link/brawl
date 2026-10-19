#pragma force_active on
struct V2 { float x; float y; };
extern "C" const float lbl_110_rodata_98;
extern "C" void fn_110_B860(V2* dst, const V2* src);

struct Result;
struct Fighter;

struct Module7c {
    virtual void f0() = 0; virtual void f1() = 0; virtual void f2() = 0; virtual void f3() = 0;
    virtual void f4() = 0; virtual void f5() = 0; virtual void f6() = 0; virtual void f7() = 0;
    virtual void f8() = 0; virtual void f9() = 0; virtual void f10() = 0; virtual void f11() = 0;
    virtual void action() = 0;
};
struct Module64 {
    virtual void f0() = 0; virtual void f1() = 0; virtual void f2() = 0; virtual void f3() = 0;
    virtual void f4() = 0; virtual void f5() = 0; virtual void f6() = 0; virtual void f7() = 0;
    virtual void f8() = 0; virtual void f9() = 0; virtual void f10() = 0; virtual void f11() = 0;
    virtual void f12() = 0; virtual void f13() = 0; virtual void f14() = 0; virtual void f15() = 0;
    virtual void f16() = 0; virtual void f17() = 0; virtual void f18() = 0; virtual void f19() = 0;
    virtual void f20() = 0; virtual void f21() = 0; virtual void f22() = 0;
    virtual Result* get() = 0;
};
struct ResultPrefix { int x; int y; };
struct Result : ResultPrefix {
    virtual void f0() = 0; virtual void f1() = 0;
    virtual void f2() = 0; virtual void f3() = 0;
    virtual float get(Fighter*, int, int) = 0;
};
struct Accesser {
    char pad64[0x64];
    Module64* module64;
    char pad14[0x14];
    Module7c* module7c;
};
struct Fighter {
    char pad[0xD8];
    Accesser* accesser;
};
struct Local {
    unsigned char flag;
    unsigned char pad[3];
    V2 vectors[4];
};

extern "C" void fn_110_14054(void*, V2* self, Fighter* fighter) {
    fighter->accesser->module7c->action();
    Result* result = fighter->accesser->module64->get();
    float value = result->get(fighter, 0xFA3, 0);

    Local local;
    local.flag = 0;
    local.vectors[3].x = lbl_110_rodata_98;
    local.vectors[3].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x20), &local.vectors[3]);
    local.vectors[2].x = lbl_110_rodata_98;
    local.vectors[2].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x30), &local.vectors[2]);
    local.vectors[1].x = value;
    local.vectors[1].y = value;
    fn_110_B860((V2*)((char*)self + 0x28), &local.vectors[1]);
    local.vectors[0].x = value;
    local.vectors[0].y = value;
    fn_110_B860((V2*)((char*)self + 0x38), &local.vectors[0]);
    *((unsigned char*)self + 0x15) |= 0x80;
}
