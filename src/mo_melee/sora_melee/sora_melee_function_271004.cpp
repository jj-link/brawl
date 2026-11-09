#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#include <ec/ec_mgr.h>
#include <ef/ef_id.h>
#pragma force_active on
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
virtual void processDefault(); virtual void processBegin(); virtual void slot2(); virtual void slot3(); virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision(); virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera(); virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd(); virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug(); virtual void slot20(); virtual void init(); virtual void slot22(); virtual void slot23(); virtual void loadGroundData(); virtual void slot25(); virtual void setupMelee(); virtual void slot27(); virtual void setVisibilityByClipping(); virtual void slot29(); virtual void receiveCollMsg(); virtual void slot31(); virtual void receiveCollMsg_Heading(); virtual void receiveCollMsg_Wall(); virtual void receiveCollMsg_Attack(); virtual void unloadData(); virtual void getModelCount(); virtual void slot37(); virtual void slot38(); virtual void setStageData(); virtual void getStageData(); virtual void initStageData(); virtual void setMdlIndex(); virtual void getMdlIndex(); virtual void isEnableCalcCollision(); virtual void enableCalcCollision(); virtual void disableCalcCollision(); virtual void getNodeIndex(); virtual void getNodePosition(); virtual void getNodePosition_2(); virtual bool getNodeMatrix(Matrix*, unsigned long, unsigned long); virtual bool getNodeMatrix_2(Matrix*, unsigned long, const char*);
};
struct Object { char pad0[4]; int state; char pad8[5]; unsigned char flagD; char padE[2]; Ground* ground; EfID efId; unsigned short delay; char pad1a[2]; Vec3f pos; Vec3f rot; Vec3f scale; float timer; unsigned char flag44; };
extern "C" { extern int lbl_27_data_57D1C; extern char lbl_27_data_57D20[]; void fn_8003E6DC(const Matrix*, Vec3f*);
void fn_27_271004(Object* self, float delta) {
if (!self->flag44) {
float timer=self->timer;
if (timer >= (float)self->delay) {
Matrix mat(true);
if (!self->ground->getNodeMatrix_2(&mat,0,lbl_27_data_57D20)) self->ground->getNodeMatrix(&mat,0,0);
float x,y,z; z=mat(2,3); y=mat(1,3); x=mat(0,3);
self->pos.m_x=x; self->pos.m_y=y; self->pos.m_z=z;
mat.getRotate(&self->rot); fn_8003E6DC(&mat,&self->scale);
g_ecMgr->setEffect(self->efId,&self->pos,&self->rot,&self->scale);
self->flagD=1; self->flag44=1;
} else self->timer=timer+delta;
} else self->state=lbl_27_data_57D1C;
}
}