#pragma force_active on
#pragma fp_contract off
#include <nw4r/math/math_arithmetic.h>
struct Constants { float x[21]; };
extern "C" const Constants lbl_50_rodata_A0;
struct Pad { char p[0x3c]; };
struct Obj : Pad {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
virtual void v10();
virtual void v11();
virtual void v12();
virtual void v13();
virtual void v14();
virtual void v15();
virtual void v16();
virtual void v17();
virtual void v18();
virtual void v19();
virtual void v20();
virtual void v21();
virtual void v22();
virtual void v23();
virtual void v24();
virtual void v25();
virtual void v26();
virtual void v27();
virtual void v28();
virtual void v29();
virtual void v30();
virtual void v31();
virtual void v32();
virtual void v33();
virtual void v34();
virtual void v35();
virtual void v36();
virtual void v37();
virtual void v38();
virtual void v39();
virtual float* params();
virtual void v41();
virtual void v42();
virtual void v43();
virtual void v44();
virtual void v45();
virtual void v46();
virtual void v47();
virtual void v48();
virtual void v49();
virtual void v50();
virtual void v51();
virtual void v52();
virtual void v53();
virtual void v54();
virtual void v55();
virtual void v56();
virtual void v57();
virtual void v58();
virtual void v59();
virtual void v60();
virtual void v61();
virtual void v62();
virtual void v63();
virtual void v64();
virtual void v65();
virtual void v66();
virtual void v67();
virtual void v68();
virtual void v69();
virtual void v70();
virtual void v71();
virtual void v72();
virtual void v73();
virtual void v74();
virtual void v75();
virtual void v76();
virtual void v77();
virtual void v78();
virtual void v79();
virtual void v80();
virtual void v81();
virtual void v82();
virtual void v83();
virtual void v84();
virtual void v85();
virtual void v86();
virtual void v87();
virtual void v88();
virtual void v89();
virtual void v90();
virtual void v91();
virtual void v92();
virtual void v93();
virtual void v94();
virtual void v95();
virtual void v96();
virtual void v97();
virtual void v98();
virtual void v99();
virtual void v100();
virtual void v101();
virtual void v102();
virtual void v103();
virtual void v104();
virtual void v105();
virtual void v106();
virtual void v107();
virtual void v108();
virtual void v109();
virtual void v110();
virtual void v111();
virtual void v112();
virtual void v113();
virtual void v114();
virtual void v115();
virtual void v116();
virtual void v117();
virtual void v118();
virtual void set(int,int,int,void*);

char p40[8];
void** anim;
char p4c[0x150-0x4c];
unsigned char state;
char p151[3];
float timer;
char p158[12];
unsigned char flag;
char p165[7];
float x,y,z;
char p178[8];
unsigned char* command;
unsigned char* status;
char p188[4];
int arg;
char sound[8];
float soundTimer;
int handle,handle3d;
};
extern "C" {
float randf__Fv();
extern void* g_sndSystem;
int playSE__9sndSystemF5SndIDiiii(void*,int,int,int,int,int);
float getFrame__16gfModelAnimationFd(void*);
int playSE__14snd3DGeneratorF5SndIDiii(void*,int,int,int,int);
void stopSE__14snd3DGeneratorFll(void*,int,int);
void fn_80075F1C(void*,int,int);
void fn_50_41CC(Obj* o,float dt) {
const Constants* d=&lbl_50_rodata_A0;
float* p=o->params();
if(!p) return;
o->timer-=dt;
if(o->timer<d->x[0]) o->timer=d->x[0];
o->soundTimer-=dt;
if(o->soundTimer<d->x[0]) o->soundTimer=d->x[0];
switch(o->state) {
case 0:
o->set(1,1,0,&o->arg);
if(o->flag==1) o->timer=p[0]; else o->timer=p[1];
o->flag=0;
o->handle=-1; o->handle3d=-1;
o->x=d->x[0]; o->y=d->x[0]; o->z=d->x[4];
o->state=1;
break;
case 1:
if(d->x[0]==o->timer) {
if(randf__Fv()<p[2]) {
o->handle=playSE__9sndSystemF5SndIDiiii(g_sndSystem,0x1b85,0,0,0,-1);
o->timer=d->x[5]; o->soundTimer=d->x[6]; o->state=2;
} else o->state=0;
}
break;
case 2:
if(d->x[0]==o->timer) {
o->timer=p[3]; *o->command=3; o->state=3;
}
break;
case 3:
if(d->x[0]==o->timer) {
o->x=d->x[0]; o->y=d->x[0]; o->z=d->x[0];
float r=randf__Fv();
float diff=p[5]-p[4];
o->timer=p[4]+diff*r;
o->state=4;
} else {
o->x=d->x[0]; o->y=d->x[0];
o->z=d->x[4]*(o->timer/nw4r::math::FAbs(d->x[4]));
}
break;
case 4:
if(d->x[0]==o->timer) {
o->timer=p[3]; *o->command=6; o->state=5;
} else if(o->status[0]==3 || o->status[1]==3) {
o->set(0,1,0,&o->arg);
void* a=o->anim[0];
if(!a) return;
float f=getFrame__16gfModelAnimationFd(a);
if(d->x[0]==f || d->x[7]==f || d->x[8]==f || d->x[9]==f)
o->handle3d=playSE__14snd3DGeneratorF5SndIDiii(o->sound,0x1b86,0,0,-1);
} else {
o->set(1,1,0,&o->arg);
if(o->handle3d!=-1) {
stopSE__14snd3DGeneratorFll(o->sound,o->handle3d,5);
o->handle3d=-1;
}
}
break;
case 5:
if(d->x[0]==o->timer) {
o->state=0;
} else {
o->x=d->x[0]; o->y=d->x[0];
o->z=d->x[4]*(d->x[10]-o->timer/nw4r::math::FAbs(d->x[4]));
}
break;
}
if(d->x[0]==o->soundTimer && o->handle!=-1) {
fn_80075F1C(g_sndSystem,o->handle,0);
o->handle=-1;
}
}
}
