#include <st/stage.h>
#include <gr/collision/gr_collision.h>
#include <sr/sr_common.h>
#pragma force_active on
struct Pad { char pad[0x3c]; };
#define V(n) virtual void n();
struct Obj : Pad {
virtual void processDefault();
virtual void processBegin();
virtual void slot2();
virtual void processUpdate();
virtual void processPreMapCorrection();
virtual void processMapCorrection();
virtual void processFixPosition();
virtual void processPreCollision();
virtual void processCollision();
virtual void processCatch();
virtual void processHit();
virtual void processCamera();
virtual void processFixCamera();
virtual void processEffect();
virtual void slot14();
virtual void processEnd();
virtual void renderPre();
virtual void renderOpa();
virtual void renderXlu();
virtual void processDebug();
virtual void renderDebug();
virtual void init();
virtual void slot22();
virtual void slot23();
virtual void loadGroundData();
virtual void bindData();
virtual void setupMelee();
virtual void setVisibility();
virtual void setVisibilityByClipping();
virtual void setVisibilityAttachedEffect();
virtual void receiveCollMsg();
virtual void receiveCollMsg_Landing();
virtual void receiveCollMsg_Heading();
virtual void receiveCollMsg_Wall();
virtual void receiveCollMsg_Attack();
virtual void unloadData();
virtual void fn_63_3378();
virtual void slot37(void*, int, int);
virtual void slot38();
virtual void fn_63_59C(void*);
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45();
virtual void slot46();
virtual void slot47();
virtual void slot48();
virtual void slot49();
virtual void slot50();
virtual void slot51();
virtual void slot52();
virtual void slot53();
virtual void slot54();
virtual void slot55();
virtual void slot56();
virtual void slot57();
virtual void slot58();
virtual void slot59();
virtual void slot60();
virtual void slot61();
virtual void slot62();
virtual void slot63();
virtual void slot64();
virtual void slot65();
virtual void slot66();
virtual void slot67();
virtual void slot68();
virtual void slot69();
virtual void slot70();
virtual void slot71();
virtual void slot72();
virtual void slot73();
virtual void slot74();
virtual void slot75();
virtual void slot76();
virtual void slot77();
virtual void slot78();
virtual void slot79();
virtual void slot80();
virtual void slot81();
virtual void slot82();
virtual void slot83();
virtual void slot84();
virtual void slot85();
virtual void slot86();
virtual void slot87();
virtual void slot88();
virtual void slot89();
virtual void slot90();
virtual void slot91();
virtual void slot92();
virtual void slot93();
virtual void slot94();
virtual void slot95();
virtual void slot96();
virtual void slot97();
virtual void slot98();
virtual void slot99();
virtual void slot100();
virtual void slot101();
virtual void slot102();
virtual void slot103();
virtual void slot104();
virtual void slot105();
virtual void slot106();
virtual void slot107();
virtual void slot108();
virtual void slot109();
virtual void slot110();
virtual void slot111();
virtual void slot112();
virtual void slot113();
virtual void slot114();
virtual void slot115(void*);
virtual void slot116(int);
virtual void slot117();
virtual void slot118();
virtual void slot119();
virtual void slot120();
virtual void slot121();
virtual void slot122();
virtual void slot123(void*);
virtual void slot124(void*);
virtual void slot125(void*);
virtual void slot126(void*);
virtual void slot127(int);
virtual void slot128(void*);
virtual void slot129(void*);
virtual void slot130();
virtual void slot131();
virtual void slot132();
virtual void slot133();
virtual void slot134(void*);
virtual void slot135(void*);
virtual void slot136(void*);
virtual void slot137(void*);
virtual void slot138(void*);
};
extern "C" {
extern char lbl_63_data_0[];
Obj* fn_63_33A4(int, const char*, const char*);
Obj* fn_63_398C(int, const char*, const char*);
Obj* fn_63_3A98(int, const char*, const char*);
Obj* fn_63_4F5C(int, const char*, const char*);
Obj* fn_63_5190(int, const char*, const char*);
void fn_63_2414(Stage*, void*, void*, Ground*);
void fn_63_5A4(Stage* stage, int kind) {
 int id;
 Obj* ground;
 void* mem;
 char* data = lbl_63_data_0;
 switch (kind) {
 case 19: ground=fn_63_398C(10,data+0x38,data+0x40); id=1; break;
 case 1: ground=fn_63_3A98(20,data+0x50,data+0x58); id=0; break;
 case 22: ground=fn_63_4F5C(40,data+0x68,data+0x70); id=2; break;
 case 23: ground=fn_63_33A4(44,data+0x80,data+0x94); id=2; break;
 case 27: ground=fn_63_5190(50,data+0xa8,data+0xb0); id=3; break;
 default: ground=0; break;
 }
 if (ground) {
 stage->addGround((Ground*)ground);
 ground->slot37(*(void**)((char*)stage+0x1a0),0,0);
 ground->fn_63_59C(*(void**)((char*)stage+0x9c));
 ground->slot115((char*)stage+0x1e0);
 ground->slot116(id);
 ground->slot123((char*)stage+0x1dc);
 ground->slot124((char*)stage+0x1e4);
 switch(kind) {
 case 1:
 ground->slot125((char*)stage+0x214);
 ground->slot126((char*)stage+0x304);
 ground->slot127(*(int*)((char*)stage+0x45c));
 ground->slot134((char*)stage+0x305);
 ground->slot135((char*)stage+0x306);
 ground->slot136((char*)stage+0x324);
 ground->slot137((char*)stage+0x348);
 ground->slot138((char*)stage+0x1ec);
 if ((char*)stage + 0x204 != 0 && ground != 0) {
 mem = operator new(0x28, Heaps::StageInstance);
 if (mem) {
 fn_63_2414(stage,mem,(void*)((int)stage+0x204),(Ground*)ground);
 stage->setCollision(grCollision::create(stage,mem,(Ground*)ground,1));
 operator delete(mem);
 }
 }
 break;
 case 22: ground->slot128((char*)stage+0x34c); ground->slot129((char*)stage+0x370); break;
 case 27: ground->slot128((char*)stage+0x394); ground->slot129((char*)stage+0x3f8); break;
 }
 }
}
}