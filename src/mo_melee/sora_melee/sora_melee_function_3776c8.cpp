#include <mt/mt_vector.h>
#pragma force_active on

extern const float lbl_27_rodata_7C00;
extern const float lbl_27_rodata_7C04;

class ftManager {
public:
    void* getOwner(int id);
};
extern ftManager* g_ftManager;

extern "C" {
unsigned int fn_27_111DD0(void* owner);
unsigned int fn_27_111E90(void* owner);
}

#define U(n) virtual void unused##n();

class Obj8_base { public: char pad[0x3c]; };
class Obj8 : public Obj8_base {
public:
    U(0) U(1) U(2) U(3) U(4) U(5) U(6) U(7)
    U(8) U(9) U(10) U(11) U(12) U(13) U(14) U(15)
    U(16) U(17) U(18) U(19) U(20) U(21) U(22) U(23)
    U(24) U(25) U(26) U(27) U(28) U(29) U(30) U(31)
    U(32) U(33) U(34) U(35) U(36) U(37) U(38) U(39)
    U(40)
    virtual int slot41();
};

class ObjP14 {
public:
    U(0) U(1) U(2)
    virtual int slot3();
};

class ObjP5C {
public:
    U(0) U(1) U(2) U(3)
    virtual void slot4();
};

class ObjPC {
public:
    U(0) U(1) U(2) U(3)
    virtual Vec3f slot4();
    U(5) U(6) U(7) U(8)
    virtual float slot9();
};

class ObjP70 {
public:
    U(0) U(1) U(2)
    virtual void slot3(int, void*);
    U(4) U(5) U(6) U(7) U(8) U(9) U(10) U(11)
    U(12) U(13) U(14) U(15)
    virtual int slot16();
};

class ObjPA8 {
public:
    U(0) U(1) U(2) U(3) U(4) U(5) U(6) U(7)
    U(8) U(9) U(10) U(11) U(12) U(13) U(14) U(15)
    U(16) U(17) U(18) U(19) U(20) U(21) U(22) U(23)
    U(24) U(25) U(26) U(27) U(28) U(29) U(30)
    virtual void slot31(int, float, float);
    U(32) U(33) U(34) U(35) U(36) U(37) U(38) U(39)
    U(40) U(41) U(42) U(43) U(44) U(45) U(46) U(47)
    U(48) U(49) U(50) U(51) U(52) U(53)
    virtual void slot54(int, int, int);
    U(55)
    virtual void slot56(int, float, float);
};

struct Mods {
    char pad0[0xc];
    ObjPC* pc;
    char pad1[4];
    ObjP14* p14;
    char pad2[0x44];
    ObjP5C* p5c;
    char pad3[0x10];
    ObjP70* p70;
    char pad4[0x34];
    ObjPA8* pa8;
};

struct Acc {
    char pad0[8];
    Obj8* obj8;
    char pad1[0xcc];
    Mods* mods;
};

struct Self {
    char pad[0xc];
    Acc* acc;
    int id;
};

extern "C" int fn_27_3776C8(Self* self, Vec3f* outPos, float* outF) {
    if (self->acc->obj8->slot41() == 0) {
        goto fail;
    }
    self->acc->mods->p5c->slot4();
    if (self->acc->mods->p14->slot3() != 0) {
        goto fail;
    }
    {
        int v = self->acc->mods->p70->slot16();
        if (v < 0x11) {
            if (v < 0xa) {
                if (v >= 0) {
                    goto body;
                }
            }
            goto fail;
        } else if (v >= 0x18) {
            goto fail;
        }
    }
body:
    {
        Vec3f pos = self->acc->mods->pc->slot4();
        outPos->m_x = pos.m_x;
        outPos->m_y = pos.m_y;
        outPos->m_z = pos.m_z;
    }
    *outF = self->acc->mods->pc->slot9();
    self->acc->mods->pa8->slot31(0, lbl_27_rodata_7C00, lbl_27_rodata_7C04);
    void* owner = g_ftManager->getOwner(self->id);
    if (fn_27_111E90(owner) == 1U) {
        self->acc->mods->pa8->slot54(1, 1, 1);
    }
    if (fn_27_111DD0(owner) == 1U) {
        self->acc->mods->pa8->slot54(0x44, 1, 1);
    }
    self->acc->mods->pa8->slot56(0xff, lbl_27_rodata_7C00, lbl_27_rodata_7C04);
    self->acc->mods->p70->slot3(0x115, self->acc);
    return 1;
fail:
    return 0;
}
