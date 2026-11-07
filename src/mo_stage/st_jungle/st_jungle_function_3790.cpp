#include <types.h>
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <snd/snd_system.h>
#pragma force_active on
extern "C" {
extern char lbl_51_data_EB8[];
extern char lbl_51_data_EC4[];
extern const float lbl_51_rodata_60[];
}
struct Ground_base { char pad[0x3c]; };
struct Limits { char pad[4]; float top; char pad8[8]; float bottom; };
class Ground : public Ground_base {
public:
virtual void processDefault(); virtual void processBegin(); virtual void fn_51_3534(); virtual void processUpdate();
virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision();
virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera();
virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd();
virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug();
virtual void renderDebug(); virtual void init(); virtual void fn_51_34CC(); virtual void fn_51_3714();
virtual void loadGroundData(); virtual void bindData(); virtual void setupMelee(); virtual void setVisibility();
virtual void setVisibilityByClipping(); virtual void setVisibilityAttachedEffect(); virtual void receiveCollMsg(); virtual void receiveCollMsg_Landing();
virtual void receiveCollMsg_Heading(); virtual void receiveCollMsg_Wall(); virtual void receiveCollMsg_Attack(); virtual void unloadData();
virtual void fn_51_33B4(); virtual void startup(); virtual void fn_51_39C8(); virtual void fn_51_994();
virtual void fn_51_33AC(); virtual void fn_51_33A8(); virtual void fn_51_2830(); virtual void fn_51_33A0();
virtual void fn_51_3394(); virtual void fn_51_3384(); virtual void fn_51_3374(); virtual void getNodeIndex();
virtual void getNodePosition(); virtual void getNodePosition_2(Vec3f*, u32, const char*); virtual void getNodeMatrix(); virtual void getNodeMatrix_2();
virtual void setNodeVisibility(); virtual void setNodeVisibility_2(); virtual void setNodeVisibilityAll(); virtual void isNodeVisible();
virtual void setNodeCollision(); virtual void setNodeCollision_2(); virtual void getNodeScale(); virtual void getNodeScale_2();
virtual void setValid(); virtual void setValidAttachedEffect(); virtual void fn_51_3370(); virtual void fn_51_336C();
virtual void fn_51_3364(); virtual void setMotionRatio(); virtual void setMotionFrame(); virtual float getMotionFrame(u32);
char pad40[0x118]; int state; Limits* limits; char pad160[0x38]; snd3DGenerator gen; char pad1a0[4]; int id1; int id2; int flag;
};
extern "C" void fn_51_3790(Ground* self) {
const float* c = lbl_51_rodata_60;
if (self->state == 0) {
Vec3f pos;
pos.m_x = c[0]; pos.m_y = c[0]; pos.m_z = c[0];
self->gen.setPos(&pos);
self->getNodePosition_2(&pos, 0, lbl_51_data_EB8);
if (pos.m_y < c[1] + self->limits->top && pos.m_y > self->limits->bottom - c[1]) {
if (self->id1 == -1) self->id1 = self->gen.playSE((SndID)0x1b8b, 0, 0xf0, -1);
} else {
if (self->id1 != -1) { self->gen.stopSE(self->id1, 0xf0); self->id1 = -1; }
}
self->getNodePosition_2(&pos, 0, lbl_51_data_EC4);
if (pos.m_y > self->limits->bottom - c[1]) {
if (self->id1 == -1) self->id1 = self->gen.playSE((SndID)0x1b8a, 0, 0xf0, -1);
if (self->id2 == -1) self->id2 = self->gen.playSE((SndID)0x1b91, 0, 0xf0, -1);
} else {
if (self->id1 != -1) { self->gen.stopSE(self->id1, 0xf0); self->id1 = -1; }
if (self->id2 != -1) { self->gen.stopSE(self->id2, 0xf0); self->id2 = -1; }
}
if (self->getMotionFrame(0) >= c[2]) {
if (self->flag == -1) { g_sndSystem->playSE((SndID)0x1b92, 0, 0, 0, -1); self->flag = 0; }
} else self->flag = -1;
}
}