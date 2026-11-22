#pragma force_active on
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scnmdl.h>
class Object_vptr_0 {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2();
virtual void slot3(); virtual void slot4(); virtual void slot5();
virtual void slot6(); virtual void slot7(); virtual void slot8();
virtual void slot9(); virtual void slot10(); virtual void slot11();
virtual void slot12(); virtual void slot13(void*);
};
struct Self {
char pad0[0x30]; MuObject* object; MuObject* entries[50];
char padFC[0x60]; Object_vptr_0* container; char pad160[0xE0];
int counters[50]; int current; char pad30C[4]; bool active[50];
};
struct Obj { MuObject* entries[194]; int unk308; };
extern "C" {
extern Object_vptr_0* lbl_805A033C;
extern char lbl_8059E678[6]; extern char lbl_8059E670[8];
extern float lbl_805A2870;
int fn_800B5328(MuObject*);
int sprintf(char*, const char*, ...);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}
inline void select(Obj* self, unsigned int arg1, bool* active) {
float frame = lbl_805A2870;
*active = false;
self->unk308 = arg1;
self->entries[arg1 + 13]->setFrameNode(frame);
self->entries[self->unk308 + 13]->setFrameMatCol(lbl_805A2870);
}
inline void updateContainer(Self* self,int i) {
char buf[6]={};
Object_vptr_0* container=self->container;
lbl_805A033C->slot13(container);
Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(lbl_805A033C,container,lbl_8059E678);
sprintf(buf,lbl_8059E670,i);
container->slot13(self->entries[i]->m_sceneModel);
self->current=i; self->object->setFrameNode(lbl_805A2870);
}
extern "C" void fn_8010C540(Self* self) {
for(int i=0;i<50;++i) {
if(self->active[i]) {
self->counters[i]++;
int n = fn_800B5328(self->entries[i]);
if(n==self->counters[i])
{ self->counters[i]=0;
select((Obj*)self,i, &self->active[i]); updateContainer(self,i); }
self->entries[i]->setFrameNode((float)self->counters[i]);
self->entries[i]->setFrameMatCol((float)self->counters[i]);
}
}
}
