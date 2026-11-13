#include <gf/gf_model.h>
#include <mu/mu_object.h>
#pragma force_active on
extern "C" {
extern char lbl_28_data_0[];
extern float lbl_28_rodata_0[];
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void setLoop__16gfModelAnimationFd(void*, bool);
}
struct AdvMenuName {
 char pad[0x124]; unsigned char initialized; char pad2[0x0B];
 MuObject* obj130; MuObject* obj134; MuObject* obj138; MuObject* obj13C; MuObject* obj140;
 char pad3[4]; MuObject* obj148; char pad4[0x0C]; void* mdl158; void* mdl15C;
};
extern "C" void fn_28_1D10(AdvMenuName* self) {
 char* data;
 float* rodata;
 rodata = lbl_28_rodata_0;
 data = lbl_28_data_0;
 MuObject* obj148 = self->obj148;
 MuObject* obj130 = self->obj130;
 MuObject* obj138 = self->obj138;
 MuObject* obj134 = self->obj134;
 MuObject* obj13C;
 MuObject* obj140;
 obj140 = self->obj140;
 obj13C = self->obj13C;
 if (!self->initialized) {
  Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdl15C, obj140->m_sceneModel, data + 0xEC);
  obj148->m_modelAnim->setUpdateRate(rodata[0x94 / 4]);
  obj130->setFrameNode(rodata[0xA0 / 4]);
  obj130->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(rodata[0x94 / 4]);
  obj138->changeNodeAnimNIf(data + 0x12C);
  obj138->changeVisAnimNIf(data + 0x12C);
  setLoop__16gfModelAnimationFd(obj138->m_modelAnim, false);
  obj138->setFrameNode(rodata[0x8C / 4]);
  obj138->m_modelAnim->m_anmObjChrRes->SetUpdateRate(rodata[0x94 / 4]);
  obj138->setFrameVisible(rodata[0x8C / 4]);
  obj138->m_modelAnim->m_anmObjVisRes->SetUpdateRate(rodata[0x94 / 4]);
  obj138->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(rodata[0x8C / 4]);
  obj140->changeClrAnimNIf(data + 0x144);
 }
 if (self->initialized) {
  Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdl158, self->obj13C->m_sceneModel, data + 0xEC);
  obj134->changeNodeAnimNIf(data + 0x12C);
  obj134->changeVisAnimNIf(data + 0x12C);
  obj134->m_modelAnim->setUpdateRate(rodata[0x94 / 4]);
  obj13C->changeClrAnimNIf(data + 0x15C);
 }
}