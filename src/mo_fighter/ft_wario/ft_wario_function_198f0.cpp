#pragma opt_propagation off
#include <so/so_module_accesser.h>
#pragma force_active on
extern "C" {
extern const unsigned char lbl_110_data_5EF0[], lbl_110_data_212C[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_110_1526C(void*);
}
struct Pair8 { int a; int b; };
struct Module {
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(int); virtual void v8(); virtual void v9();
    virtual void v10(int,int); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual Pair8 v15(short*); virtual int v16(int,bool);
    virtual void v17(); virtual void v18(); virtual int v19(unsigned long);
    virtual void v20(unsigned long); virtual void v21(unsigned long);
    virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(float);
};
struct Params {
    unsigned char pad0[0x0C]; float f0C;
    unsigned char pad1[0x20]; float f30; float f34;
};
struct WarioView { unsigned char prefix[0x2980]; const Params* params; };
inline int test(Module* m, int zero) { return m->v16(zero, zero); }
extern "C" void fn_110_198F0(void*, soModuleAccesser* accesser) {
    const unsigned char* en = reinterpret_cast<const unsigned char*>(accesser->m_enumerationStart);
    Module* r30 = *reinterpret_cast<Module* const*>(en + 0x64);
    Module* r29 = *reinterpret_cast<Module* const*>(en + 0x1C);
    Module* r28 = *reinterpret_cast<Module* const*>(en + 0x7C);
    const Params* p = static_cast<WarioView*>(
        __dynamic_cast(accesser->m_stageObject, 0x3c, lbl_110_data_5EF0, lbl_110_data_212C, 1))->params;
    short s = 1;
    Pair8 pr = r28->v15(&s);
    float t = fn_110_1526C(&pr);
    float start = p->f34;
    if (t <= start) {
        if (test(r29, 0) != 0) {
            r29->v7(0);
            r30->v20(0x2200000A);
        }
    } else {
        float f31 = p->f30 * ((t - start) / (p->f0C - start));
        if (test(r29, 0) != 0) {
            r29->v50(f31);
            return;
        }
        if (r30->v19(0x2200000A) != 0) {
            r29->v10(0, 0);
            r29->v50(f31);
            r30->v21(0x2200000A);
        }
    }
}