#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern const float lbl_27_rodata_2B18;

class PostureObj {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual float s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual float s22();
};

class WorkObj {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual int s17(unsigned int flag);
};

struct PhysHdr {
    int pad0;
    int pad1;
};

class PhysObj : public PhysHdr {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(unsigned int v);
    virtual void s40(); virtual void s41(); virtual void s42(float* p, int a, int b);
};

extern "C" void fn_27_1DD668(void* self, soModuleAccesser* a) {
    float sp[3];
    sp[0] = lbl_27_rodata_2B18;
    sp[1] = lbl_27_rodata_2B18;
    sp[2] = lbl_27_rodata_2B18;

    PostureObj* posture = (PostureObj*)a->m_enumerationStart->m_postureModule;
    float f31 = posture->s22();
    float c = soValueAccesser::getConstantFloat(a, 0xFA0, 0);
    f31 = c * f31;
    float d = posture->s9();
    sp[0] = d * f31;

    WorkObj* work = (WorkObj*)a->m_enumerationStart->m_workManageModule;
    int n;
    if (work->s17(0x22000000) == 0) {
        n = soValueAccesser::getConstantInt(a, 0x5DC1, 0);
    } else {
        n = soValueAccesser::getConstantInt(a, 0x5DC0, 0);
    }

    ((PhysObj*)a->m_enumerationStart->m_physicsModule)->s42(sp, n, 1);
    ((PhysObj*)a->m_enumerationStart->m_physicsModule)->s39(0);
}
