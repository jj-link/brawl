#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on
struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base { public:
virtual void processDefault(); virtual void processBegin(); virtual void processAnim(); virtual void processUpdate(); virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision(); virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera(); virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd(); virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug(); virtual void renderDebug(); virtual void init(); virtual void fn_60_2A0(); virtual void fn_60_440(); virtual void createObjPokeTrainer(); virtual void fn_60_620C(); virtual void fn_60_6208(); virtual void fn_60_61FC(); virtual void fn_60_61F4(); virtual void fn_60_61EC(); virtual void getItemPac(); virtual void getItemGenPac(); virtual void getItemPacEnemyFigure(); virtual void getEnemyPac(); virtual void getAdvRadarData(); virtual void initializeStage(); virtual void closeStage(); virtual void renderDebugPositions(); virtual void fn_60_438(); virtual void process(); };
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base { public:
virtual void processDefault(); virtual void processBegin(); virtual void processAnim(); virtual void processUpdate(); virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision(); virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera(); virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd(); virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug(); virtual void renderDebug(); virtual void init(); virtual void slot22(); virtual void slot23(); virtual void loadGroundData(); virtual void bindData(); virtual void setupMelee(); virtual void setVisibility(); virtual void setVisibilityByClipping(); virtual void setVisibilityAttachedEffect(); virtual void receiveCollMsg(); virtual void receiveCollMsg_Landing(); virtual void receiveCollMsg_Heading(); virtual void receiveCollMsg_Wall(); virtual void receiveCollMsg_Attack(); virtual void unloadData(); virtual void fn_60_6588(); virtual void startup(u32, u32, u32); virtual void setNode(); virtual void fn_60_1A80(u32); };
extern char lbl_60_data_0[]; extern const float lbl_60_rodata_0[];
extern "C" Ground* create__8grMadeinFiPCcPCcQ25Heaps8HeapType(int,const char*,const char*,int);
extern "C" void addGround__5StageFP6Ground(Stage*,Ground*);
extern "C" void initializeEntity__8grMadeinFv(void*); extern "C" float randf__Fv();
extern "C" void setMotion__8grMadeinFUl(void*,u32); extern "C" void setPos__9grGimmickFP5Vec3f(void*,Vec3f*); extern "C" void setRot__9grGimmickFP5Vec3f(void*,Vec3f*); extern "C" void setScale__9grGimmickFP5Vec3f(void*,Vec3f*);
extern "C" void fn_60_1D8C(Stage* stage,u32 kind) {
const float* lbl=lbl_60_rodata_0; char* data=lbl_60_data_0; f32 rot[3]; f32 pos[3]; f32 scale[3]; Ground* g;
switch(kind){case 3:g=create__8grMadeinFiPCcPCcQ25Heaps8HeapType(3,data+0x214,data+0x214,15);break;case 18:g=create__8grMadeinFiPCcPCcQ25Heaps8HeapType(15,data+0x21C,data+0x21C,15);break;case 19:g=create__8grMadeinFiPCcPCcQ25Heaps8HeapType(16,data+0x224,data+0x224,15);break;case 15:g=create__8grMadeinFiPCcPCcQ25Heaps8HeapType(17,data+0x230,data+0x230,15);break;case 16:g=create__8grMadeinFiPCcPCcQ25Heaps8HeapType(18,data+0x238,data+0x238,15);break;case 17:g=create__8grMadeinFiPCcPCcQ25Heaps8HeapType(19,data+0x240,data+0x240,15);break;default:g=0;break;}
if(g){addGround__5StageFP6Ground(stage,g);g->startup(*(u32*)((char*)stage+0x1A0),0,0);g->fn_60_1A80(*(u32*)((char*)stage+0x9C));
if(kind==3){rot[0]=lbl[0];rot[1]=lbl[0];rot[2]=lbl[0];pos[0]=lbl[0];pos[1]=lbl[19];pos[2]=lbl[0];}
if(kind==0x12){rot[0]=lbl[0];rot[1]=lbl[0];rot[2]=lbl[0];}
if(kind==0x13){rot[0]=lbl[0];rot[1]=lbl[5];rot[2]=lbl[0];}
setRot__9grGimmickFP5Vec3f(g,(Vec3f*)rot);initializeEntity__8grMadeinFv(g);
if((u8)(kind+0xF1)<=2U){
rot[1]=lbl[21]-lbl[20]*randf__Fv(); rot[0]=lbl[0]; rot[2]=lbl[0];
f32 t31=lbl[22]+(lbl[11]-(lbl[8]*randf__Fv()));
pos[0]=lbl[16]-lbl[23]*randf__Fv();pos[1]=lbl[0];pos[2]=t31;
setMotion__8grMadeinFUl(g,0);setPos__9grGimmickFP5Vec3f(g,(Vec3f*)pos);setRot__9grGimmickFP5Vec3f(g,(Vec3f*)rot);
scale[0]=lbl[10];scale[1]=lbl[10];scale[2]=lbl[10];setScale__9grGimmickFP5Vec3f(g,(Vec3f*)scale);
}}
}