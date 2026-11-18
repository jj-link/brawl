#include <so/so_module_accesser.h>
#include <math.h>
#pragma force_active on

struct V2 { float x, y; };

union U2 {
    unsigned long long u;
    V2 v;
};

class WorkM {
public:
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual int getInt(unsigned long id);
};

class CtrlM {
public:
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3C();
    virtual void s40();
    virtual void s44();
    virtual float getStick();
};

struct Pad8 { char p[8]; };

class G : public Pad8 {
public:
    virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8C();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8(); virtual void vBC();
    virtual void vC0(); virtual void vC4(); virtual void vC8(); virtual void vCC();
    virtual void vD0(); virtual void vD4(); virtual void vD8(); virtual void vDC();
    virtual void vE0();
    virtual int fE4(int, int);
    virtual void vE8();
    virtual unsigned long long fEC(int, int);
    virtual void vF0(); virtual void vF4(); virtual void vF8(); virtual void vFC();
    virtual void v100(); virtual void v104(); virtual void v108(); virtual void v10C();
    virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11C();
    virtual void v120(); virtual void v124(); virtual void v128(); virtual void v12C();
    virtual void v130(); virtual void v134(); virtual void v138(); virtual void v13C();
    virtual void v140(); virtual void v144(); virtual void v148(); virtual void v14C();
    virtual void v150(); virtual void v154(); virtual void v158(); virtual void v15C();
    virtual void v160(); virtual void v164(); virtual void v168(); virtual void v16C();
    virtual void v170(); virtual void v174(); virtual void v178(); virtual void v17C();
    virtual void v180(); virtual void v184(); virtual void v188(); virtual void v18C();
    virtual void v190(); virtual void v194(); virtual void v198(); virtual void v19C();
    virtual void v1A0(); virtual void v1A4(); virtual void v1A8(); virtual void v1AC();
    virtual void v1B0(); virtual void v1B4(); virtual void v1B8(); virtual void v1BC();
    virtual void v1C0(); virtual void v1C4(); virtual void v1C8();
    virtual int f1CC(int, int);
};

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
float fn_118_E474(float y, float x);
extern const float lbl_118_rodata_30[];
}

extern "C" int fn_118_F6EC(float dir, soModuleAccesser* acc) {
    const float* k = lbl_118_rodata_30;
    G* ground = reinterpret_cast<G*>(acc->m_enumerationStart->m_groundModule);
    WorkM* work = reinterpret_cast<WorkM*>(acc->m_enumerationStart->m_workManageModule);
    U2 t2;
    U2 t1;
    V2 p;
    int v = work->getInt(0x1000000B);
    float c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xC97, 0);
    float x = reinterpret_cast<CtrlM*>(acc->m_enumerationStart->m_controllerModule)->getStick();
    bool ok;
    if (v <= 0 && (float)fabs((double)x) >= c && x * dir < k[0]) {
        p.x = k[0];
        p.y = k[3];
        float sign;
        if (dir >= k[0]) {
            t1.u = reinterpret_cast<G*>(acc->m_enumerationStart->m_groundModule)->fEC(2, 0);
            p = t1.v;
            sign = k[2];
        } else {
            t2.u = reinterpret_cast<G*>(acc->m_enumerationStart->m_groundModule)->fEC(4, 0);
            p = t2.v;
            sign = k[3];
        }
        float a = k[12] + k[16] * (sign * fn_118_E474(p.x, p.y));
        if (a >= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xC9C, 0) ||
            a <= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xC9D, 0)) {
            ok = false;
        } else {
            ok = true;
        }
        if (ok && ground->fE4(1, 0) == 0) {
            if (dir >= k[0]) {
                if (ground->f1CC(2, 0)) return 1;
            } else {
                if (ground->f1CC(4, 0)) return 1;
            }
        }
    }
    return 0;
}
