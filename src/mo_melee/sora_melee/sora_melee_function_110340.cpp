#pragma force_active on
#pragma fp_contract on
#pragma fp_relaxed on
struct Config { float levels[3]; char pad[16]; int minimum; int count; };
struct State { char pad[0x44]; Config* config; char pad48[12]; int entry; int count; unsigned int target; int timer; char pad64[16]; int sound; int channel; };
struct Base { char pad[8]; };
struct Module : Base {
virtual void dummy0();
virtual void dummy1();
virtual void dummy2();
virtual void dummy3();
virtual void dummy4();
virtual void dummy5();
virtual void dummy6();
virtual void dummy7();
virtual void dummy8();
virtual void dummy9();
virtual void dummy10();
virtual void dummy11();
virtual void dummy12();
virtual void dummy13();
virtual void dummy14();
virtual void dummy15();
virtual void dummy16();
virtual void dummy17();
virtual float value(int);
};
extern "C" {
extern void* g_ftManager;
extern void* g_sndSystem;
int isFighterActivate__9ftManagerFii(void*,int,int);
signed char getFighterOperationType__9ftManagerFi(void*,int);
void* getFighter__9ftManagerFii(void*,int,int);
Module* fn_27_14D468(void*);
unsigned int fn_27_14D4E4(void*);
unsigned int fn_80077DA0(void*,int);
void fn_80075F1C(void*,int,int);
int playSE__9sndSystemF5SndIDiiii(void*,int,int,int,int,int);
int fn_27_110340(State* self,int entry,float value) {
if (!isFighterActivate__9ftManagerFii(g_ftManager,entry,-1) || self->entry==entry || getFighterOperationType__9ftManagerFi(g_ftManager,entry)==1) return 0;
Config* config;
void* fighter=getFighter__9ftManagerFii(g_ftManager,entry,-1);
config=self->config;
Module* module=fn_27_14D468(fighter);
float current=module->value(0);
if(current < (float)config->minimum || self->count < config->count) return 0;
self->target=fn_27_14D4E4(fighter);
if(self->target==0xFFFFFFFF) return 0;
if(self->sound!=-1 && fn_80077DA0(g_sndSystem,self->sound)==1) fn_80075F1C(g_sndSystem,self->sound,0);
self->sound=-1;
int level;
if(value>=self->config->levels[2]) level=2;
else if(value>=self->config->levels[1]) level=1;
else level= value>=self->config->levels[0] ? 0 : -1;
self->sound=playSE__9sndSystemF5SndIDiiii(g_sndSystem,level==2?29:30,self->channel,0,0,-1);
self->entry=entry;
self->timer=0;
return 1;
}
}
