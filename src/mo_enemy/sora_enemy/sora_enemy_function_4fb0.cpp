#include <em/em_info.h>
#include <so/so_module_accesser.h>
#pragma force_active on

#define V1(n) virtual void unused##n();
#define V2(n) V1(n##a) V1(n##b)
#define V4(n) V2(n##a) V2(n##b)
#define V8(n) V4(n##a) V4(n##b)
#define V16(n) V8(n##a) V8(n##b)
#define V32(n) V16(n##a) V16(n##b)
#define V64(n) V32(n##a) V32(n##b)

extern "C" void fn_41_4D5C(void* self);
extern "C" void fn_41_4EB8(void* self);
extern "C" void fn_27_4254(void* self, int arg);
extern const float lbl_41_rodata_18;

struct EnemySelf {
    char pad0[0x60];
    soModuleAccesser* accesser;
    char pad64[0xAC - 0x64];
    EnemyKind kind;
    char padB0[0xD8 - 0xB0];
    u8 unkD8;
    char padD9[0x113C - 0xD9];
    u8 unk113C;
};

class StatusIface {
public:
    V32(a) V2(b)
    virtual void setStatus(int, soModuleAccesser*);
};

class EffectIface {
public:
    V16(a) V4(b) V1(d)
    virtual void setEffect(int);
};

class LinkIface {
public:
    V8(a)
    virtual void setLink(int);
    virtual unsigned int getLink(int);
    V64(c) V8(d) V4(e) V1(f)
    virtual void setLink89(int);
};

struct Pad8 { int pad0; int pad4; };
struct Mod8 : Pad8 {
    V8(a)
    virtual void setDamage(float);
    virtual void update();
};

extern "C" void fn_41_4FB0(EnemySelf* self) {
    s32 standBy = (s32)emInfo::getInstance()->StandByStatusKind(self->kind);
    if (standBy != -1) {
        soModuleAccesser* accesser = self->accesser;
        ((StatusIface*)accesser->m_enumerationStart->m_statusModule)->setStatus(standBy, accesser);
    }
    fn_41_4D5C(self);
    fn_41_4EB8(self);
    ((EffectIface*)self->accesser->m_enumerationStart->m_effectModule)->setEffect(0);
    ((Mod8*)self->accesser->m_enumerationStart->m_damageModule)->setDamage(lbl_41_rodata_18);
    ((Mod8*)self->accesser->m_enumerationStart->m_damageModule)->update();
    ((LinkIface*)self->accesser->m_enumerationStart->m_linkModule)->setLink89(1);
    for (int i = 3; i < 5; i++) {
        if (((LinkIface*)self->accesser->m_enumerationStart->m_linkModule)->getLink(i) == 1U) {
            ((LinkIface*)self->accesser->m_enumerationStart->m_linkModule)->setLink(i);
        }
    }
    ((Mod8*)self->accesser->m_enumerationStart->m_modelModule)->update();
    fn_27_4254(self, 1);
    self->unk113C = 1;
    self->unkD8 = 0;
}
