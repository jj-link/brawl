#include <so/so_module_accesser.h>
#include <ec/ec_mgr.h>
#pragma force_active on

extern "C" void fn_98_14584(Vec3f* out, const Vec3f* in);

class PkCheckObj {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int s4();
};

struct PkPad {
    int a;
    int b;
};

class PkMoveObj : public PkPad {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual Vec3f s36(const Vec3f* in, int flag);
};

extern "C" void fn_98_144E8(char* self, int unused, const Vec3f* input) {
    PkCheckObj* check = *(PkCheckObj**)(*(char**)(self + 0xd8) + 0x64);
    unsigned long id = check->s4();
    if (id != 0) {
        Vec3f pos;
        PkMoveObj* move = *(PkMoveObj**)(*(char**)(self + 0xd8) + 0x4);
        Vec3f adjusted = move->s36(input, 0);
        fn_98_14584(&pos, &adjusted);
        g_ecMgr->setPos(id, &pos);
    }
}
