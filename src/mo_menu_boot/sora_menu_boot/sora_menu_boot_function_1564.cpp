#include <gf/gf_archive.h>
#include <mu/mu_object.h>
#pragma force_active on

extern "C" {
extern char lbl_22_data_1C0[];
extern char lbl_22_data_1D0[];
extern float lbl_22_rodata_0;
extern float lbl_22_rodata_4;
void* fn_800AFBFC(const void*, unsigned int, void*, unsigned int);
void fn_801AAFF0(void*, int);
void fn_801AB014(void*, int);
void fn_800B6838(MuObject*, const Vec3f*);
}

struct Self {
    char pad[0x5C];
    void* data;
    void* res1;
    void* res2;
    void* unk68;
    void* task;
    MuObject* object;
};

extern "C" void fn_22_1564(Self* self, gfArchive* archive) {
    self->task = fn_800AFBFC(lbl_22_data_1C0, 0x10, archive, 0xA);
    self->data = archive->getData(Data_Type_Misc, 0, 0xFFFE);
    self->res1 = archive->getData(Data_Type_Model, 0, 0xFFFE);
    self->res2 = archive->getData(Data_Type_Model, 1, 0xFFFE);
    nw4r::g3d::ResFile::Init(&self->res1);
    nw4r::g3d::ResFile::Init(&self->res2);
    MuObject* obj = MuObject::create((nw4r::g3d::ResFile*)&self->res2, lbl_22_data_1D0, 1, 0, (HeapType)0x2A);
    self->object = obj;
    fn_801AAFF0(obj->m_scnMdl, 0xFF);
    fn_801AB014(obj->m_scnMdl, 0xFF);
    Vec3f pos;
    pos.m_x = lbl_22_rodata_0;
    pos.m_y = lbl_22_rodata_4;
    pos.m_z = lbl_22_rodata_0;
    fn_800B6838(self->object, &pos);
}
