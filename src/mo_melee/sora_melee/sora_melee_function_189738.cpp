#include <so/stageobject.h>
#include <so/so_value_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

class ModNumA {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual int f16(void*);
};

class ModP14 {
public:
    virtual void d0(); virtual void d1(); virtual void d2();
    virtual int f3();
};

class ModP7C {
public:
    virtual void d0(); virtual void d1(); virtual void d2();
    virtual void d3(); virtual void d4(); virtual void d5();
    virtual void* f6(int);
};

class ModPC {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual Vec3f f4();
};

class ModWork {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual int f4(unsigned long);
    virtual void f5(int, unsigned long);
    virtual void d6();
    virtual void f7(unsigned long);
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual float f12(unsigned long);
    virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16();
    virtual int f17(unsigned long);
    virtual void f18(unsigned long);
};

class ModCtrl {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
    virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27();
    virtual void d28(); virtual void d29(); virtual void d30(); virtual void d31();
    virtual void d32(); virtual void d33(); virtual void d34(); virtual void d35();
    virtual void d36(); virtual void d37();
    virtual unsigned int f38();
};

class ModP88 {
public:
    virtual void d0(); virtual void d1(); virtual void d2();
    virtual void d3(); virtual void d4(); virtual void d5();
    virtual void f6(int, const Vec3f*, Vec3f*, int, int, float);
    virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10();
    virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14();
    virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18();
    virtual void d19(); virtual void d20(); virtual void d21(); virtual void d22();
    virtual void d23(); virtual void d24(); virtual void d25(); virtual void d26();
    virtual void d27(); virtual void d28(); virtual void d29(); virtual void d30();
    virtual void d31(); virtual void d32(); virtual void d33(); virtual void d34();
    virtual void d35(); virtual void d36(); virtual void d37();
    virtual void f38(int, float);
};

class ModE8 {
public:
    virtual void d0(); virtual void d1(); virtual void d2();
    virtual void d3(); virtual void d4(); virtual void d5();
    virtual void f6();
    unsigned char pad[2];
    unsigned char flag;
};

struct Modules {
    char p0[0x0c]; ModPC* pC;
    char p10[0x04]; ModP14* p14;
    char p18[0x44]; ModCtrl* p5c;
    char p60[0x04]; ModWork* work;
    char p68[0x08]; ModNumA* p70;
    char p74[0x08]; ModP7C* p7c;
    char p80[0x08]; ModP88* p88;
    char p8c[0x1c]; ModNumA* pA8;
};

struct Owner {
    char pad[0xd8];
    Modules* mod;
};

extern "C" {
extern char lbl_27_data_13690[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_2518;
extern float lbl_27_rodata_251C;
void* __dynamic_cast(void*, long, const void*, const void*, long);
float fn_27_1949F0(void*);
void fn_27_165458(void*, float, float, float, float, float, unsigned long, float);
unsigned int getButtonMask__12soControllerFQ212soController9PadButton(int);
}

extern "C" void fn_27_189738(void* unused, Owner* a)
{
    if (a->mod->p70->f16(a) == 0xE0) {
        char* e = static_cast<char*>(__dynamic_cast(a->mod->p7c->f6(0), 0, lbl_27_data_13690, lbl_27_data_CDF8, 1));
        float f27 = fn_27_1949F0(a);
        ModWork* work = a->mod->work;
        fn_27_165458(a, work->f12(0x21000004),
                     soValueAccesser::getConstantFloat((soModuleAccesser*)a, 0xbbb, 0),
                     soValueAccesser::getConstantFloat((soModuleAccesser*)a, 0xbb9, 0),
                     soValueAccesser::getConstantFloat((soModuleAccesser*)a, 0xbba, 0),
                     soValueAccesser::getConstantFloat((soModuleAccesser*)a, 0xc2e, 0),
                     0x21000004, f27);
        float v = a->mod->work->f12(0x21000004);
        Vec2f vel(v, lbl_27_rodata_2518);
        *reinterpret_cast<Vec2f*>(e + 8) = vel;
    }

    if (a->mod->pA8->f16(0) == 0x1B) {
        int var = a->mod->work->f4(0x20000002);
        if (a->mod->work->f17(0x1200000D) == 0) {
            ModCtrl* ctrl = a->mod->p5c;
            if (ctrl->f38() & getButtonMask__12soControllerFQ212soController9PadButton(0)) {
                ModWork* w2 = a->mod->work;
                int k = soValueAccesser::getConstantInt((soModuleAccesser*)a, 0x5a75, 0);
                var = k - w2->f4(0x20000004);
                ModP88* p88;
                p88->f6(0xB, &(p88 = a->mod->p88, a->mod->pC)->f4(), &Vec3f(lbl_27_rodata_2518, lbl_27_rodata_2518, lbl_27_rodata_2518), 0, -1, lbl_27_rodata_251C);
            }
        }

        if (a->mod->p14->f3() == 2) {
            ModE8* o = static_cast<ModE8*>(a->mod->p7c->f6(1));
            if (var > 0) {
                var -= 1;
                if (var <= 0) {
                    a->mod->work->f18(0x1200000D);
                }
            }
            if (var > 0) {
                int n = a->mod->work->f4(0x20000003);
                n = n + 1;
                if (n > soValueAccesser::getConstantInt((soModuleAccesser*)a, 0x5a76, 0)) {
                    n = 0;
                    a->mod->work->f7(0x20000004);
                }
                a->mod->work->f5(n, 0x20000003);
                o->f6();
                o->flag = 1;
            } else {
                o->flag = 0;
            }
        } else if (var > 0) {
            var -= 1;
        }

        a->mod->work->f5(var, 0x20000002);
        if (a->mod->work->f17(0x22000011) == 0) {
            var = a->mod->work->f4(0x1000001B);
            if (var < soValueAccesser::getConstantInt((soModuleAccesser*)a, 0x5a74, 0)) {
                a->mod->work->f18(0x22000011);
                a->mod->p88->f38(0x16, lbl_27_rodata_2518);
            }
        }
    }
}
