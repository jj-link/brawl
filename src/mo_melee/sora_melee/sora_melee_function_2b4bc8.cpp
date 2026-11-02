#include <types.h>
#include <it/item.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_5EBC;
extern "C" const float lbl_27_rodata_5EB8;

union PosResult {
    unsigned long long value;
    struct {
        float x, y;
    } pos;
};

struct PosSource {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Vec3f getPos();
};

struct GroundSource {
    virtual void v0();
    virtual void v1();
    virtual unsigned long long get();
};

struct Obj {
    u8 pad0[0x8c];
    PosSource src;
    u8 pad90;
    u8 flag91;
    u8 pad92[2];
    Vec3f pos;
    u8 padA0[0xc];
    Vec3f vAC;
    Vec3f vB8;
    Vec3f vC4;
    float fD0;
    float fD4;
    GroundSource ground;
    u8 padDC;
    u8 flagDD_bit : 1;
    u8 flagDD_rest : 7;
    u8 padDE[2];
    float fE0;
};

struct Holder {
    u8 pad[8];
    BaseItem* item;
};

static inline void clearTemps() {
    Vec3f cy;
    Vec3f bz;
    cy.m_y = lbl_27_rodata_5EBC;
    bz.m_z = lbl_27_rodata_5EBC;
}

extern "C" void fn_27_2B4BC8(Obj* obj, Vec3f* offset, int useGround, Holder* holder) {
    Vec3f pos = obj->src.getPos();
    float x = pos.m_x + offset->m_x;
    float z = pos.m_z + offset->m_z;
    pos.m_x = x;
    pos.m_z = z;
    if (useGround && obj->flagDD_bit) {
        PosResult g;
        PosResult r;
        r.value = obj->ground.get();
        g = r;
        g.pos.y += offset->m_y;
        obj->fE0 = g.pos.y;
    } else {
        pos.m_y += offset->m_y;
    }
    BaseItem* item = holder->item;
    Vec3f a;
    a.m_x = lbl_27_rodata_5EBC;
    clearTemps();
    obj->pos = pos;
    Vec3f zero(lbl_27_rodata_5EBC, lbl_27_rodata_5EBC, lbl_27_rodata_5EBC);
    obj->vAC = zero;
    Vec3f b8(item->getParam((itValueAccesser::ParamFloat)0xD6B),
             item->getParam((itValueAccesser::ParamFloat)0xD50),
             lbl_27_rodata_5EBC);
    obj->vB8 = b8;
    Vec3f c4(item->getParam((itValueAccesser::ParamFloat)0xD6D),
             item->getParam((itValueAccesser::ParamFloat)0xD6E),
             lbl_27_rodata_5EB8);
    obj->vC4 = c4;
    obj->flag91 |= 0x80;
}
