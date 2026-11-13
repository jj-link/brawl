#include <types.h>
#include <gf/gf_task_scheduler.h>
#pragma force_active on

struct Flags;

// Virtual table slots: method k sits at offset 0x8 + 4*(k-1).
class VTab {
public:
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual Flags* m7(u32 idx);
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual s32 m17();
    virtual s32 m18(s32 flags);
    virtual void m19(s32 flags);
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual s32 m34(u8 a, u8 b);
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56(s32 a, s32 b, bool c, s32 d);
};

struct Flags {
    u8 pad0[5];
    u8 flag7 : 1;
    u8 rest : 7;
};

struct D8Obj {
    u8 pad0[0x5C];
    VTab* p5C;
    u8 pad1[0x4];
    VTab* p64;
    u8 pad2[0x8];
    VTab* p70;
    u8 pad3[0x8];
    VTab* p7C;
};

struct Inner {
    u8 pad[0xD8];
    D8Obj* p;
};

struct Outer {
    u8 pad[0x60];
    Inner* p;
};

struct Arg1 {
    u8 pad0[0xC];
    u32 id;
    u8 pad1[0x13];
    u8 b23;
    u8 b24;
};

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" VTab* fn_27_8CD54(void*);
extern "C" void fn_111_D4D8(void*, f32, void*, void*);
extern "C" u32 lbl_111_bss_1B4;
extern "C" const char lbl_111_data_1D44[];
extern "C" const char lbl_111_data_1E44[];

extern "C" void fn_111_7E5C(Outer* arg0, f32 farg0, Arg1* arg1, Inner* arg2) {
    if (arg1 != 0) {
        if (arg0->p->p->p70->m17() == 0x116) {
            void* dyn = __dynamic_cast(
                gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)0xA, arg1->id),
                0x3C, lbl_111_data_1D44, lbl_111_data_1E44, 0);
            if (dyn != 0 && fn_27_8CD54(dyn)->m34(arg1->b24, arg1->b23) == 0) {
                if (arg2->p->p64->m18(0x22000010) == 0) {
                    arg2->p->p64->m19(0x22000010);
                    Flags* f = arg2->p->p7C->m7(5);
                    f->flag7 = 0;
                    Flags* g = arg2->p->p7C->m7(6);
                    g->flag7 = 0;
                    arg2->p->p5C->m56(0xC, 0, 0, -1);
                }
                fn_111_D4D8(&lbl_111_bss_1B4, farg0, arg1, arg2);
            }
        }
    }
}
