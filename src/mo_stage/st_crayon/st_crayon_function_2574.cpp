#pragma force_active on
struct Vec3f { float x,y,z; };
struct Data { char pad[0xe8]; void* field; };
struct Handle { void* unused; Data* data; };
struct AnimHandle { void* unused; void* animation; };
struct Base { char pad[0x3c]; };
struct Obj : Base {
virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();
virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual void v16();virtual void v17();virtual void v18();virtual void v19();
virtual void v20();virtual void v21();virtual void v22();virtual void v23();virtual void v24();virtual void v25();virtual void v26();virtual void v27();virtual void v28();virtual void v29();
virtual void v30();virtual void v31();virtual void v32();virtual void v33();virtual void v34();virtual void v35();virtual void v36();virtual void v37();virtual void v38();virtual void v39();
virtual void v40();virtual void v41();virtual void v42();virtual void v43();virtual void v44();virtual void v45();virtual void v46();virtual void v47();
virtual void getPos(Vec3f*,int,int);
virtual void v49();
virtual void v50();virtual void v51();virtual void v52();virtual void v53();virtual void v54();virtual void v55();virtual void v56();virtual void v57();virtual void v58();virtual void v59();
virtual void v60();virtual void v61();virtual void v62();virtual void v63();virtual void v64();virtual void v65();virtual void v66();virtual void v67();virtual void v68();virtual void v69();
virtual void v70();virtual void v71();virtual void v72();virtual void v73();virtual void v74();virtual void v75();virtual void v76();virtual void v77();virtual void v78();virtual void v79();
virtual void v80();virtual void v81();
virtual void change(int,int);
virtual void v83();virtual void v84();virtual void v85();virtual void v86();virtual void v87();virtual void v88();virtual void v89();
virtual void v90();virtual void v91();virtual void v92();virtual void v93();virtual void v94();virtual void v95();virtual void v96();virtual void v97();virtual void v98();virtual void v99();
virtual void v100();virtual void v101();virtual void v102();virtual void v103();virtual void v104();virtual void v105();virtual void v106();virtual void v107();virtual void v108();virtual void v109();
virtual void v110();virtual void v111();virtual void v112();virtual void v113();virtual void v114();
virtual float duration();
char pad40[4]; Handle* handle; AnimHandle* animHandle;
char pad4c[0x118]; Data* data; void* field; void* animation;
char pad170[2]; unsigned char state; char pad173[0x19]; char generator[4];
};
extern "C" {
extern const float lbl_56_rodata_58[6];
extern float lbl_56_bss_1C;
void setUpdateRate__16gfModelAnimationFf(void*,float);
int playSE__14snd3DGeneratorF5SndIDiii(void*,int,int,int,int);
void setPos__14snd3DGeneratorFP5Vec3f(void*,Vec3f*);
}
extern "C" void fn_56_2574(Obj* self,float delta) {
Vec3f pos;
const float* constants=lbl_56_rodata_58;
float t;
self->data=self->handle->data;
self->field=self->data->field;
self->animation=self->animHandle->animation;
switch(self->state) {
case 0:
break;
case 1:
self->change(1,0);
setUpdateRate__16gfModelAnimationFf(self->animation,delta);
lbl_56_bss_1C=constants[4];
playSE__14snd3DGeneratorF5SndIDiii(self->generator,0x1be0,0,0,-1);
self->state=2;
case 2:
t=lbl_56_bss_1C-delta;
lbl_56_bss_1C=t;
if(t<=constants[0]) self->state=3;
break;
case 3:
self->change(3,0);
setUpdateRate__16gfModelAnimationFf(self->animation,delta);
lbl_56_bss_1C=self->duration();
self->state=4;
case 4:
t=lbl_56_bss_1C-delta;
lbl_56_bss_1C=t;
if(t<=constants[0]) self->state=5;
break;
case 5:
self->change(5,0);
setUpdateRate__16gfModelAnimationFf(self->animation,delta);
lbl_56_bss_1C=constants[5];
self->state=6;
case 6:
t=lbl_56_bss_1C-delta;
lbl_56_bss_1C=t;
if(t<=constants[0]) self->state=0;
break;
}
self->getPos(&pos,1,1);
setPos__14snd3DGeneratorFP5Vec3f(self->generator,&pos);
}
