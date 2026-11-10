#include <mu/mu_msg.h>
#include <mu/mu_object.h>
#include <gm/gm_global.h>
#pragma force_active on
struct Entry { char pad[0x10]; void* value; };
struct Manager {
virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11();
virtual void a12(); virtual void remove(void*);
};
struct Base { char pad[0x668]; };
struct Self : Base {
virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
virtual void v16(); virtual void update(int,int,int); virtual void select(int);
int index; char pad670[8]; MuMsg* msg; char pad67c[8]; MuObject* object;
char pad688[4]; Manager* manager; char pad690[4]; void* data;
int first; int selected; char pad6a0[8]; int value18; int value19; int value1a;
Entry* entry1; Entry* entry2; Entry* entry3;
};
extern int lbl_2_data_3470[];
extern "C" int fn_8004D6C4(void*,int,char*);
extern "C" int fn_2_25B60(int,void*);
extern "C" void fn_2_2A58C(void*,int);
extern "C" void fn_2_2A3B8(void* arg,int flag) {
Self* self=static_cast<Self*>(arg);
int value; int* p; int row; int i; char buf[24]; void* data=self->data;
fn_8004D6C4(g_GameGlobal,(int)data,buf);
self->msg->printf(self->index+1,buf);
self->manager->remove(self->entry1->value);
self->manager->remove(self->entry2->value);
self->manager->remove(self->entry3->value);
i=self->first; row=0; p=&lbl_2_data_3470[i];
while(row<7 && i<27) {
if(*p>=0 && *p<24) value=fn_2_25B60(*p,data);
else switch(*p) {
case 24: value=self->value18; break;
case 25: value=self->value19; break;
case 26: value=self->value1a; break;
}
self->update(*p,value,row);
++row; ++p; ++i;
}
self->object->setFrameNode((float)self->selected);
fn_2_2A58C(self,flag);
self->select(lbl_2_data_3470[self->first+self->selected]);
}