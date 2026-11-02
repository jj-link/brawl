#include <types.h>

#pragma force_active on

inline double fabs_(double value) {
    return __fabs(value);
}

class WorkMod {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int getInt(u32 index);
    virtual void setInt(int value, u32 index);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float getFloat(u32 index);
    virtual void setFloat(float value, u32 index);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual u32 isFlag(u32 index);
};

class CtrlMod {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual float getStickX();
};

class PostureMod {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float getLr();
};

class MotionMod {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float getFrame();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual float getWeight();
    virtual void v24();
    virtual void setWeight(float w);
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void add2ndAnimChr(float frame, float rate, int kind, bool flag);
    virtual void remove2ndAnimChr();
};

struct ModEnum {
    char p0[8];
    MotionMod* motion;     // 0x8
    PostureMod* posture;   // 0xc
    char p1[0x5c - 0x10];
    CtrlMod* controller;   // 0x5c
    char p2[4];
    WorkMod* work;         // 0x64
};

struct Accesser {
    char p0[0xd8];
    ModEnum* e;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
extern "C" const float lbl_27_rodata_2070;
extern "C" const float lbl_27_rodata_2074;

extern "C" void fn_27_1673A4(void*, Accesser* self) {
    float cur = self->e->work->getFloat(0x21000004);
    float diff = self->e->controller->getStickX() - cur;
    float v = cur + diff * getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xC4A, 0);
    float absV = fabs_(v);
    self->e->work->setFloat(v, 0x21000004);
    if (absV < getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xC4B, 0)) {
        self->e->motion->remove2ndAnimChr();
        MotionMod* m = self->e->motion;
        m->setWeight(lbl_27_rodata_2074 - m->getWeight());
        self->e->work->setInt(-1, 0x20000002);
    } else {
        int prev = self->e->work->getInt(0x20000002);
        int kind;
        if (v * self->e->posture->getLr() > lbl_27_rodata_2070) {
            kind = self->e->work->getInt(0x20000000);
        } else {
            kind = self->e->work->getInt(0x20000001);
        }
        if (kind != prev) {
            self->e->motion->remove2ndAnimChr();
            MotionMod* m = self->e->motion;
            m->add2ndAnimChr(m->getFrame(), lbl_27_rodata_2074, kind, true);
            self->e->work->setInt(kind, 0x20000002);
        }
        MotionMod* m = self->e->motion;
        m->setWeight(lbl_27_rodata_2074 - absV - m->getWeight());
    }
    if (self->e->work->isFlag(0x22000010) == 1) {
        self->e->work->setInt(self->e->work->getInt(0x20000003) + 1, 0x20000003);
    }
}
