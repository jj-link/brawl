#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <types.h>
#pragma force_active on

extern float lbl_27_data_2EEE8;

struct Vec3 {
    float x, y, z;
};

class ValIface {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual float s12(u32);
};

struct QHeader {
    int h0;
    int h1;
};

class QIface : public QHeader {
public:
    virtual void t0(); virtual void t1(); virtual void t2(); virtual void t3();
    virtual void t4(); virtual void t5(); virtual void t6(); virtual void t7();
    virtual void t8(); virtual void t9(); virtual void t10(); virtual void t11();
    virtual void t12(); virtual void t13(); virtual void t14(); virtual void t15();
    virtual void t16(); virtual void t17(); virtual void t18(); virtual void t19();
    virtual void t20(); virtual void t21(); virtual void t22(); virtual void t23();
    virtual void s26(int, Vec3*);
    virtual void t27(); virtual void t28(); virtual void t29(); virtual void t30();
    virtual void t31(); virtual void t32(); virtual void t33(); virtual void t34();
    virtual int s35(u32);
};

struct AccData {
    char pad0[4];
    QIface* q;
    char pad1[0x5C];
    ValIface* v;
};

struct ModAcc {
    char pad[0xd8];
    AccData* data;
};

extern "C" void fn_27_16A220(void*, ModAcc* acc) {
    ValIface* v = acc->data->v;
    float f31 = soValueAccesser::getConstantFloat((soModuleAccesser*)acc, 0xca1, 0);
    f31 = v->s12(0x11000003) / f31;
    float c = soValueAccesser::getConstantFloat((soModuleAccesser*)acc, 0xcaf, 0);
    f31 = c * f31;
    float f1 = soValueAccesser::getConstantFloat((soModuleAccesser*)acc, 0xca2, 0);
    f31 = f1 + f31 * (lbl_27_data_2EEE8 - f1);
    float f0 = f31 * soValueAccesser::getConstantFloat((soModuleAccesser*)acc, 0xbe6, 0);
    Vec3 vec;
    vec.x = f0;
    vec.y = f0;
    vec.z = f0;
    QIface* q = acc->data->q;
    int r = q->s35(0x12c);
    q->s26(r, &vec);
}
