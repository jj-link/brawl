#include <gf/gf_scene.h>
#include <revolution/OS/OSError.h>
#pragma force_active on
extern "C" void* fn_80158BE0();
extern "C" int fn_8015A33C(void*);
extern "C" void fn_8015A358(void*);
extern "C" int fn_1_1E2CC(void*);
extern "C" int fn_1_1D2FC(void*);
extern "C" int fn_1_1D3BC(void*);
extern "C" int fn_1_1D700(void*, int, int);
extern "C" int fn_1_1D948(void*);
extern "C" int fn_1_1DE04(void*);
extern char lbl_1_data_60A8[];
struct Inner { char pad[0x5a]; unsigned char a; char pad2[0x46d]; unsigned char b; };
struct Other { char pad[0x11]; unsigned char a; };
struct Obj { char pad[8]; Inner* inner; char pad2[0x10]; int state; int id; char pad3[0x28]; Other* other; };
extern "C" int fn_1_1D0AC(Obj* p) {
 int done=0;
 int result;
 if (fn_8015A33C(fn_80158BE0())) {
 fn_8015A358(fn_80158BE0());
 } else {
 return 0;
 }
 switch(p->state) {
 case 0: p->state=fn_1_1E2CC(p); break;
 case 1: p->state=fn_1_1D2FC(p); break;
 case 2: p->state=fn_1_1D3BC(p); break;
 case 3: { int v=4; if(p->id==11) v=2; if(p->id>=31) v=6; p->state=fn_1_1D700(p,0x3ff,v); break; }
 case 4: { int a=0,b=1; switch(p->id) { case 5:a=2;b=2;break; case 14:a=8;b=2;break; case 18:a=4;b=2;break; case 19:a=0x40;b=2;break; case 27:a=4;b=4;break; } p->state=fn_1_1D700(p,a,b); break; }
 case 5: p->state=fn_1_1D700(p,0,4); break;
 case 6: p->state=fn_1_1D700(p,0,4); break;
 case 7: p->state=fn_1_1D948(p); break;
 case 8: p->state=fn_1_1DE04(p); break;
 case 9: break;
 }
 if(p->state==10) {done=1;result=0;}
 if((unsigned)(p->state-12)<=1 && p->inner->b) {done=1;result=1;OSReport(lbl_1_data_60A8,p->id);}
 if(p->state==11) {done=1;result=2;}
 if(p->state==9) {done=1;result=3;}
 if(done) {if(p->other) p->other->a=p->inner->a; gfSceneManager* mgr=gfSceneManager::getInstance(); mgr->unk1=result; mgr->processStep=2;}
 return 0;
}