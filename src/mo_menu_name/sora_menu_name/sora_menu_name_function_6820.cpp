#include <mu/mu_msg.h>
#include <snd/snd_system.h>
#include <nw4r/g3d/g3d_scngroup.h>
#pragma force_active on

struct Resource {
    char pad[0x10];
    nw4r::g3d::ScnObj* object;
};
struct Menu {
    char pad0[0x70];
    MuObject* object;
    char pad74[0xc];
    Resource* resource80;
    Resource* resource84;
    char pad88[0xc];
    nw4r::g3d::ScnGroup* group;
    char pad98[0xbc];
    MuMsg* msg;
    char pad158[0x298];
    int field3f0;
    char pad3f4[0x10];
    int index;
};
extern "C" {
extern void* g_GameGlobal;
extern char lbl_16_data_36C0[];
extern float lbl_16_rodata_268;
void fn_8004D674(void*, int, void*);
void fn_16_4ABC(void*, int, void*, int, int);
void fn_8006BCA8(char*, const void*);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}
extern "C" void fn_16_6820(Menu* self) {
    struct { unsigned short name[6]; char buffer[32]; } local;
    void* global = g_GameGlobal;
    Resource* resource = self->resource80;
    nw4r::g3d::ScnGroup* group = self->group;
    g_sndSystem->playSE((SndID)0x27, -1, 0, 0, -1);
    fn_8004D674(global, self->index, local.name);
    fn_16_4ABC(self, 4, local.name, 5, 1);
    nw4r::g3d::ScnGroup* nextGroup = self->group;
    self->field3f0 = 30;
    Resource* nextResource = self->resource84;
    nextGroup->Remove(nextResource->object);
    fn_8006BCA8(local.buffer, local.name);
    self->msg->printf(10, local.buffer);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(nextGroup, nextResource->object, lbl_16_data_36C0);
    self->object->setFrameNode(lbl_16_rodata_268);
    self->object->m_modelAnim->m_anmObjChrRes->SetUpdateRate(lbl_16_rodata_268);
    self->object->setFrameMatCol(lbl_16_rodata_268);
    self->object->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(lbl_16_rodata_268);
    group->Remove(resource->object);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(group, resource->object, lbl_16_data_36C0);
}