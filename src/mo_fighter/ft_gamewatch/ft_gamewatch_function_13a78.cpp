#pragma force_active on
struct Vec2f { float m_x, m_y; };
struct AttributeFlag {
    unsigned short mask;
};
class Work {
public:
    virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual float getFloat(unsigned int);
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual bool isFlag(unsigned int);
    virtual void onFlag(unsigned int);
    virtual void offFlag(unsigned int);
};
class Motion {
public:
    virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void setRate(float);
};
class Kinetic {
public:
    virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual Vec2f getSumSpeed(const AttributeFlag&);
};
struct Modules {
    char pad0[8];
    Motion* motion;
    char pad1[0x58];
    Work* work;
    char pad2[0x14];
    Kinetic* kinetic;
};
struct soModuleAccesser {
    char pad[0xd8];
    Modules* modules;
};
static inline bool lessEqual(float a, const float* values) { return a <= values[1]; }
extern "C" {
extern const float lbl_107_rodata_A0[4];
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
void fn_107_14328(void*, soModuleAccesser*);
void fn_107_13A78(void* self, soModuleAccesser* accesser) {
    const float* constants = lbl_107_rodata_A0;
    Work& work = *accesser->modules->work;
    if (work.isFlag(0x22000010) == true) {
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xC39, 0);
        if (!work.isFlag(0x22000011)) {
            accesser->modules->motion->setRate(constants[0]);
            work.onFlag(0x22000011);
        } else {
            float direction = work.getFloat(0x21000005);
            AttributeFlag flag;
            flag.mask = 1;
            Vec2f speed = accesser->modules->kinetic->getSumSpeed(flag);
            if (lessEqual(direction * speed.m_x, constants)) {
                accesser->modules->motion->setRate(constants[2]);
                work.offFlag(0x22000010);
            }
        }
    }
    fn_107_14328(self, accesser);
}
}
