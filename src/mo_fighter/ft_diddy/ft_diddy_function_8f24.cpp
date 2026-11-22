#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on
#pragma opt_propagation off

#define VS8(b) virtual void b##0(); virtual void b##1(); virtual void b##2(); virtual void b##3(); \
    virtual void b##4(); virtual void b##5(); virtual void b##6(); virtual void b##7();

struct Pre8 { int pad0; int pad1; };
class VT {
public:
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual int v4(unsigned int id);
    virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8();
    virtual float v9();
    virtual void a10(); virtual void a11(); virtual void a12();
    virtual void v13(short* flag);
    VS8(p14_) VS8(p22_)
    virtual void a30(); virtual void a31();
    virtual int v32(const char* name);
    virtual void a33(); virtual void a34(); virtual void a35();
    virtual Vec3f v36(int a, int b);
    VS8(p37_) VS8(p45_) VS8(p53_) VS8(p61_) VS8(p69_) VS8(p77_)
    VS8(p85_) VS8(p93_) VS8(p101_)
    virtual void a109(); virtual void a110(); virtual float v111();
};
class VT8 : public Pre8 {
public:
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual int v4(unsigned int id);
    virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8();
    virtual float v9();
    virtual void a10(); virtual void a11(); virtual void a12();
    virtual void v13(short* flag);
    VS8(p14_) VS8(p22_)
    virtual void a30(); virtual void a31();
    virtual int v32(const char* name);
    virtual void a33(); virtual void a34(); virtual void a35();
    virtual Vec3f v36(int a, int b);
    VS8(p37_) VS8(p45_) VS8(p53_) VS8(p61_) VS8(p69_) VS8(p77_)
    VS8(p85_) VS8(p93_) VS8(p101_)
    virtual void a109(); virtual void a110(); virtual float v111();
};
extern "C" {
extern const float lbl_115_rodata_C;
extern const float lbl_115_rodata_20;
extern const char lbl_115_data_8[];
Vec3f* fn_115_8EF8(Vec3f*, float, float, float);
void fn_115_8F08(Vec3f*, const Vec3f*);
void fn_115_16B24(void*, Vec3f*, float*, float, float, float, int);
}
extern "C" int fn_115_8F24(void* arg0, soModuleAccesser* arg1) {
    float f31 = lbl_115_rodata_C;
    float pair[2];
    pair[0] = f31;
    pair[1] = f31;
    float f30 = f31;
    Vec3f sp20;
    int r28flag;
    fn_115_8EF8(&sp20, f31, f31, f31);
    const char* name = lbl_115_data_8;
    VT8* model = reinterpret_cast<VT8*>(arg1->m_enumerationStart->m_modelModule);
    int res = model->v32(name);
    Vec3f sp14 = model->v36(res, 0);
    fn_115_8F08(&sp20, &sp14);
    sp20.m_z = reinterpret_cast<VT8*>(arg1->m_enumerationStart->m_groundModule)->v111();
    int state = reinterpret_cast<VT*>(arg1->m_enumerationStart->m_workManageModule)->v4(0x20000002);
    if (state == 0) {
        r28flag = 0;
        float tmp = lbl_115_rodata_C;
        pair[0] = tmp;
        pair[1] = soValueAccesser::getConstantFloat(arg1, 0xFAF, 0);
        int cnt = reinterpret_cast<VT*>(arg1->m_enumerationStart->m_workManageModule)->v4(0x20000000);
        f31 = (float)cnt;
        f30 = lbl_115_rodata_20;
    } else if (state == 1) {
        short sp8 = 1;
        reinterpret_cast<VT*>(arg1->m_enumerationStart->m_kineticModule)->v13(&sp8);
        pair[0] *= soValueAccesser::getConstantFloat(arg1, 0xFB4, 0);
        pair[1] *= soValueAccesser::getConstantFloat(arg1, 0xFB4, 0);
        int cnt = reinterpret_cast<VT*>(arg1->m_enumerationStart->m_workManageModule)->v4(0x20000000);
        f31 = (float)cnt;
        r28flag = 0;
    } else {
        r28flag = 1;
    }
    float lr = reinterpret_cast<VT*>(arg1->m_enumerationStart->m_postureModule)->v9();
    fn_115_16B24(arg0, &sp20, pair, lr, f31, f30, r28flag);
    return 0;
}