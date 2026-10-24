#pragma force_active on
struct Params { float v[12]; };
struct Base { unsigned char pad[0x3c]; };
struct Ground : Base {
virtual void unused0();
virtual void unused1();
virtual void unused2();
virtual void unused3();
virtual void unused4();
virtual void unused5();
virtual void unused6();
virtual void unused7();
virtual void unused8();
virtual void unused9();
virtual void unused10();
virtual void unused11();
virtual void unused12();
virtual void unused13();
virtual void unused14();
virtual void unused15();
virtual void unused16();
virtual void unused17();
virtual void unused18();
virtual void unused19();
virtual void unused20();
virtual void unused21();
virtual void unused22();
virtual void unused23();
virtual void unused24();
virtual void unused25();
virtual void unused26();
virtual void setVisible(bool);
virtual void unused28();
virtual void unused29();
virtual void unused30();
virtual void unused31();
virtual void unused32();
virtual void unused33();
virtual void unused34();
virtual void unused35();
virtual void unused36();
virtual void unused37();
virtual void unused38();
virtual void unused39();
virtual Params* getParams();
unsigned char pad40[4];
void** model;
unsigned char pad48[4];
void* collision;
unsigned char pad50[0x100];
unsigned char state;
unsigned char pad151[3];
float timer;
Params* params;
unsigned char pad15c[0x3c];
float offset;
};
extern "C" {
extern const float lbl_51_rodata_1D0[];
extern const char lbl_51_data_81C8[];
extern void* g_ecMgr;
void setEnableCollisionStatus__6GroundFb(Ground*, bool);
void fn_801109AC(void*);
void fn_8011097C(void*);
void setDrawPrio__5ecMgrFi(void*, int);
unsigned long setEffect__5ecMgrF4EfID(void*, int);
void setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(void*, unsigned long, void*, const char*, bool);
void fn_51_11C68(Ground* self, float dt) {
const float* constants = lbl_51_rodata_1D0;
Params* p = self->getParams();
if (!p) return;
self->timer -= dt;
if (self->timer < constants[0]) self->timer = constants[0];
switch(self->state) {
case 0:
self->setVisible(false);
setEnableCollisionStatus__6GroundFb(self,false);
if(self->collision) fn_801109AC(self->collision);
self->state=1;
return;
case 2:
if(constants[0] == self->timer) {
self->setVisible(true);
setEnableCollisionStatus__6GroundFb(self,true);
if(self->collision) fn_8011097C(self->collision);
self->state=6;
}
break;
case 6:
self->offset += p->v[11]*dt;
if(self->params->v[1]+self->offset > self->params->v[4]) {
self->offset=self->params->v[4]-self->params->v[1];
self->timer=constants[1];
self->state=7;
}
break;
case 7:
if(self->timer <= constants[2]) {
setDrawPrio__5ecMgrFi(g_ecMgr,1);
unsigned long effect=setEffect__5ecMgrF4EfID(g_ecMgr,0x390003);
setDrawPrio__5ecMgrFi(g_ecMgr,-1);
setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(g_ecMgr,effect,*self->model,lbl_51_data_81C8,false);
self->state=8;
}
break;
case 8:
if(constants[0] == self->timer) self->state=0;
break;
case 1:
case 3:
case 4:
case 5:
default:
break;
}
}
}
