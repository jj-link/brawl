#include <types.h>
#pragma force_active on

struct Vec2f {
    float m_x;
    float m_y;
};
struct Vec3f {
    float m_x;
    float m_y;
    float m_z;
};

class KineticModule {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void* getEnergy(int) = 0;
};

struct Flags {
    char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
};

struct Enumeration {
    char pad[0x7c];
    KineticModule* m_kinetic;
};

struct Accesser {
    char pad[0xd8];
    const Enumeration* m_enumerationStart;
};

extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, Accesser*, int, Vec2f*, Vec3f*);
}

extern "C" void fn_27_163F78(int a1, int a2, int a3, Accesser* accesser) {
    Vec3f v3 = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    Vec2f v2 = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    fn_27_89D08(3, accesser, 12, &v2, &v3);
    KineticModule* km = accesser->m_enumerationStart->m_kinetic;
    Flags* p = (Flags*)km->getEnergy(4);
    p->flag = 0;
}
