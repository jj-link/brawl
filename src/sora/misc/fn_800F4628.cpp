#pragma force_active on
#include <mu/mu_msg.h>
#include <gf/gf_shutdown_manager.h>

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(void*, nw4r::g3d::ScnMdl*);
    char pad4[0xE0];
    void* fieldE4;
};

struct State {
    char pad0[0x40];
    Object_vptr_0* field40;
    char pad44[0x14];
    MuObject* field58;
    char pad5C[0xC];
    int field68;
    char pad6C[0x20];
    MuMsg* field8C;
    char pad90[4];
    int field94;
    int field98;
    char pad9C[0x14];
    u8 fieldB0;
};
struct Entry {
    u8 kind;
    u8 pad1[3];
    u32 index;
};
extern const Entry lbl_80408D78[];
extern float lbl_805A25C0;
extern float lbl_805A2608;
extern float lbl_805A25D4;
extern "C" float fn_800F238C(void*, int);
extern "C" void fn_800B6838(MuObject*, const Vec3f*);
extern "C" void fn_800B753C(MuObject*, float);

extern "C" void fn_800F4628(State* self) {
    MuObject* object;
    const Entry* entry = &lbl_80408D78[self->field68];
    fn_800F238C(self, entry->kind);
    Object_vptr_0* target = self->field40;
    object = self->field58;
    target->slot11(target->fieldE4, object->m_sceneModel);
    Vec3f pos;
    pos.m_x = lbl_805A25C0;
    pos.m_y = lbl_805A2608;
    pos.m_z = lbl_805A25C0;
    fn_800B6838(object, &pos);
    fn_800B753C(object, lbl_805A25C0);
    object->m_modelAnim->setUpdateRate(lbl_805A25D4);
    self->field8C->printIndex(3, entry->index, 0);
    self->field94 = 120;
    self->field98 = 0;
    self->fieldB0 = 0;
    g_gfShutdownManager.unkD = false;
}
