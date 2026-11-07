#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on
extern "C" unsigned long long fn_113_18DE4(void*);
extern "C" int fn_113_182BC(float);
extern "C" float fn_113_182E4(float*);
extern "C" void fn_113_1901C(void*);
extern "C" unsigned int fn_113_18F1C(void*);
extern "C" const float lbl_113_rodata_64;
struct Pair { unsigned int x, y; };
struct M88 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35(); virtual void s36(); virtual void s37();
    virtual void f40(int, float);
    virtual void f41(int);
};
#define ACC (*(soModuleAccesser**)((char*)a + 0x60))
#define M88P(m) (*(M88**)((char*)(*(void**)((char*)(m) + 0xd8)) + 0x88))
extern "C" void fn_113_1B79C(void* a) {
    int kind = ACC->getStatusModule().getStatusKind();
    if (kind == 0x33 || kind == 0x2e || kind == 0x2f) return;
    Pair v;
    unsigned long long raw = fn_113_18DE4(a);
    v = *(Pair*)&raw;
    int r = fn_113_182BC(*(float*)&v.x);
    if (r) r = fn_113_182BC(*(float*)&v.y);
    if ((unsigned)r == 1) {
        if (!ACC->getWorkManageModule().isFlag(0x12000003) &&
            fn_113_182E4((float*)&v) >= static_cast<soParamAccesser*>(ACC->getWorkManageModule().getParamAccesser())->getParamFloat(ACC, 0xfa2, 0)) {
            ACC->getWorkManageModule().onFlag(0x12000003);
            ACC->getWorkManageModule().setInt(soValueAccesser::getConstantInt(ACC, 0x5dc0, 0), 0x10000007);
            fn_113_1901C(a);
        } else if (ACC->getWorkManageModule().isFlag(0x12000003) == 1) {
            soModuleAccesser* m = ACC;
            float lim = static_cast<soParamAccesser*>(m->getWorkManageModule().getParamAccesser())->getParamFloat(m, 0xfa3, 0);
            if (fn_113_182E4((float*)&v) <= lim) {
                ACC->getWorkManageModule().offFlag(0x12000003);
                fn_113_1901C(a);
                M88P(ACC)->f41(0);
            }
        }
    }
    if (ACC->getWorkManageModule().isFlag(0x12000003) == 1) {
        if (ACC->getStatusModule().getStatusKind() != 0x1e && ACC->getStatusModule().getStatusKind() != 0x1f) {
            ACC->getWorkManageModule().decInt(0x10000007);
            if (ACC->getWorkManageModule().getInt(0x10000007) <= 0) {
                ACC->getStatusModule().changeStatusRequest(0x1e, ACC);
            }
        }
    }
    soModuleAccesser* m = ACC;
    int x = soValueAccesser::getConstantInt(m, 0x5dc0, 0);
    int y = soValueAccesser::getConstantInt(m, 0x5dc1, 0);
    float d = (float)(x - y);
    if (fn_113_18F1C(a) == 1) {
        bool b;
        switch (kind) {
        case 0x1e: case 0x1f: case 0x2c: b = true; break;
        default: b = false; break;
        }
        if (!b) {
            if (d == (float)ACC->getWorkManageModule().getInt(0x10000007)) {
                M88P(ACC)->f40(0, lbl_113_rodata_64);
            }
        }
    }
}
