#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern "C" float getParamFloat__8BaseItemFUl(void*, unsigned long);

class WorkMod {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual float getFloat(unsigned long);
    virtual void setFloat(float, unsigned long);
};

class AttackMod {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void setPowerMul(float);
};

extern "C" int fn_27_298348(void* unused1, void* item, void* unused2, void* other) {
    float* of = (float*)other;
    char* base = (char*)item;
    WorkMod* work = *(WorkMod**)(*(char**)(*(char**)(base + 0x60) + 0xd8) + 0x64);

    float cur = work->getFloat(0x11000000UL);
    float p1 = getParamFloat__8BaseItemFUl(item, 0x2937UL);
    float absCur = (float)(double)nw4r::math::FAbs(cur);
    float ab = of[10] * of[6];
    float v = ab * p1;
    float unusedLim = ((float)(double)nw4r::math::FAbs(v) > absCur) ? v : cur;
    (void)unusedLim;
    work->setFloat(v, 0x11000000UL);

    float p2 = getParamFloat__8BaseItemFUl(item, 0x2936UL);
    float p3 = getParamFloat__8BaseItemFUl(item, 0x293CUL);
    AttackMod* attack = *(AttackMod**)(*(char**)(*(char**)(base + 0x60) + 0xd8) + 0x1c);
    float mv = (of[10] * p2 > p3) ? p3 : of[10] * p2;
    attack->setPowerMul(mv);
    return 1;
}
