#include <types.h>
#pragma force_active on
struct Pane { u8 pad[0xB7]; u8 flags; };
class Object_vptr_0 {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2();
virtual void slot3(); virtual void slot4(); virtual void slot5();
virtual void slot6(); virtual void slot7(); virtual void slot8();
virtual void slot9(); virtual void slot10(); virtual void slot11();
virtual void slot12(); virtual Pane* slot13(const char*, int);
};
struct Manager { char pad[0x10]; Object_vptr_0* object; };
struct Config { char pad[0x20]; int mode; };
struct Item { char pad[0x14]; int value; };
struct Obj {
char pad0[4]; Config* config;
char pad1[0x78-8]; int state; u8 flags[4];
char pad2[0x1E8-0x80]; Manager* root; Manager* managers[4];
char pad3[0x25C-0x1FC]; void* handles[4];
char pad4[0x2A0-0x26C]; Item* items[0x4A];
};
extern const int lbl_8040E798[0x25][4];
extern const char* lbl_8059EE68;
extern const char* lbl_80485D98[4][4];
extern "C" void fn_80278C34(void*);
extern "C" void fn_8027AC3C(void*, void*);
static inline int findSlot(int id, int flag) {
const int* e = &lbl_8040E798[0][0];
int j;
for(j=0;j<0x4A;j++) {
if(id==e[0] && e[1]==flag) return j;
e+=2;
}
return -1;
}
extern "C" void fn_80270F48(Obj* obj, int* arg) {
int* input=arg;
Obj* p=obj;
char* data=(char*)obj+0x15C;
for(int i=0;i<4;i++) {
if(*input) {
if(obj->config->mode==0) { Pane* pane=p->managers[0]->object->slot13(lbl_8059EE68,1); pane->flags=(pane->flags & 0xFE)|1; }
Item* item=obj->items[findSlot(i+0x1F,0x11)];
fn_80278C34(item);
item->value=1;
obj->flags[i]=1;
fn_8027AC3C(p->handles[0],data);
} else {
if(obj->config->mode==0) { Pane* pane=p->managers[0]->object->slot13(lbl_8059EE68,1); pane->flags &= 0xFE; }
Item* item=obj->items[findSlot(i+0x1F,0x10)];
fn_80278C34(item);
item->value=1;
obj->flags[i]=0;
}
input+=4;
p=(Obj*)((char*)p+4);
data+=0x18;
}
int inner;
int outer=0;
const char** names=&lbl_80485D98[0][0];
const char** row;
do {
row=names;
inner=0;
do {
Pane* pane=obj->root->object->slot13(*row,1);
pane->flags &= 0xFE;
inner++;
row++;
} while(inner<4);
outer++;
names+=4;
} while(outer<4);
obj->state=0;
}
