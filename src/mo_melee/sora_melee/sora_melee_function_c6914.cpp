#pragma force_active on
extern "C" {
extern void* lbl_27_bss_F0; extern void* lbl_27_bss_5668; extern void* lbl_8059FF90; extern void* lbl_805A0360;
extern float lbl_27_rodata_EF0; extern float lbl_27_rodata_EF4; extern const char* lbl_27_data_18698[];
void* getTask__6gfTaskFi(int); void* __nw__FUlQ25Heaps8HeapType(unsigned long,int); void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*); void* getInstance__15gfTaskSchedulerFv();
void setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(void*,int,bool);
void* getTask__15gfTaskSchedulerFPCc(void*,const char*); void setPaused__6gfTaskFb(void*,bool);
}
struct Stage_base{char pad[0x3c];};
class Stage:public Stage_base{public:
virtual void processDefault(); virtual void processBegin(); virtual void processAnim(); virtual void processUpdate(); virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision(); virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera(); virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd(); virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug(); virtual void renderDebug(); virtual void init(); virtual void dtor(); virtual void createObj(); virtual void createObjPokeTrainer(); virtual void getPokeTrainerPointNum(); virtual void getPokeTrainerPointData(); virtual void getPokeTrainerPositionZ(); virtual void getPokeTrainerDrawLayer(); virtual void isAdventureStage(); virtual void getItemPac(); virtual void getItemGenPac(); virtual void getItemPacEnemyFigure(); virtual void getEnemyPac(); virtual void getAdvRadarData(); virtual void initializeStage(); virtual void closeStage(); virtual void renderDebugPositions(); virtual void loading(); virtual void process(); virtual void updateStagePositions(); virtual void debugCollision(); virtual void getAIRange(); virtual void getDefaultLightSetIndex(); virtual void getZoneLightSetIndex(); virtual void getScrollDir(); virtual void clearCameraParam(); virtual void initCameraParam(); virtual void startLoadLocalData(); virtual void isLoadLocalData(); virtual void entryLocalData(); virtual void removeLocalData(); virtual void appearanceFighterLocal(); virtual void getFighterStartPos(); virtual void getFighterReStartPos(); virtual void isReStartSamePoint(); virtual void getPokeTrainerStartPos(); virtual void getItemPosCount(); virtual void getItemPos(); virtual void getRandItemPos(); virtual void getKirifudaPos(); virtual void getKirifudaAngle(); virtual void getKirifudaScale(); virtual void getKirifudaModelType(); virtual void getPokeTrainerPosCount(); virtual void getPokeTrainerPos(); virtual void getFighterDeadEffectSizeRate(); virtual void getEnemyDeadEffectSizeRate(); virtual void getEnableZ(); virtual void getBgmID(); virtual void getBgmID_2(); virtual void getNowStepBgmID(); virtual void getBgmOptionID(); virtual void isBgmChange(); virtual void getBgmChangeID(); virtual void setBgmChange(); virtual void getBgmVolume(); virtual void getBgmPlayOffsetFrame(); virtual void isNextStepBgmEqualNowStepBgmFromFlag(); virtual void setFrameRuleTime(); virtual void getFrameRuleTime(); virtual void notifyTimmingGameStart(); virtual void isEnd(); virtual void isEventEnd(); virtual void enableDevil(); virtual void disableDevil(); virtual void isDevil(); virtual void setDevilScrool(); virtual void getLucarioFinalTechniquePosition(); virtual void startAppear(); virtual void setAppearKind(); virtual void endAppear(); virtual void getAppearTask(); virtual void forceStopAppear(); virtual void getFinalTechniqColor(); virtual void setMotionRatio(float,float); virtual void saveMotionRatio(void*); virtual void restoreMotionRatio(void*);
};
struct UnkClass0x50{virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();};
extern "C" void fn_27_C6914(void* self){
unsigned char* p=(unsigned char*)self; unsigned int id=*(unsigned int*)(p+0x44); int flag;
if(id+0x10000==0xFFFF)flag=0;else flag=getTask__6gfTaskFi(id)!=0;
if(flag==0){if(p[0x8E]!=0)p[0x8D]=1;}
if(p[0x8D]!=0){
if(lbl_27_bss_F0==0){void* s=__nw__FUlQ25Heaps8HeapType(0x4C,2);if(s!=0)s=fn_27_5BCD0(s);lbl_27_bss_F0=s;}
if(fn_27_5BEA8(lbl_27_bss_F0)==1){
setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(getInstance__15gfTaskSchedulerFv(),0xB,false);
setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(getInstance__15gfTaskSchedulerFv(),0xA,false);
setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(getInstance__15gfTaskSchedulerFv(),0xC,false);
setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(getInstance__15gfTaskSchedulerFv(),0x6,false);
setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(getInstance__15gfTaskSchedulerFv(),0x21,false);
setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(getInstance__15gfTaskSchedulerFv(),0x9,false);
setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(getInstance__15gfTaskSchedulerFv(),0xE,false);
setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(getInstance__15gfTaskSchedulerFv(),0xF,false);
((unsigned char*)lbl_8059FF90)[0x74]=0;((unsigned char*)lbl_805A0360)[0x41]=0;
if(lbl_27_bss_5668!=0)((Stage*)lbl_27_bss_5668)->restoreMotionRatio(p+0x7C);
int i;void* sched=getInstance__15gfTaskSchedulerFv();const char** names=lbl_27_data_18698;i=0;
do{void* t=getTask__15gfTaskSchedulerFPCc(sched,*names);if(t!=0)setPaused__6gfTaskFb(t,false);i++;names++;}while(i<2);
*(int*)(p+0x44)=-1;*(int*)(p+0x48)=0;*(int*)(p+0x4C)=0;((UnkClass0x50*)(p+0x50))->v8();
float ef4;float ef0;ef0=lbl_27_rodata_EF0;ef4=lbl_27_rodata_EF4;
p[0x8D]=0;p[0x8E]=0;*(float*)(p+0x80)=ef0;*(float*)(p+0x7C)=ef0;*(float*)(p+0x88)=ef4;*(float*)(p+0x84)=ef4;
}}
}