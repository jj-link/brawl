#include <gf/gf_archive.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(void*, void*);
 char pad[0xe0]; void* fieldE4;
};
struct IfManager { char pad[0x14]; Object_vptr_0* scene; };
struct Hdr { int data[12]; };
struct Block { int a[7]; float f1, f2; int rest[15]; };
struct Task {
 char pad0[0x2c]; unsigned char flags; char pad2d[0xf];
 void* vtable; gfArchive* archive; char pad44[0x4c];
 void* scene; char pad94[4]; unsigned char active; char pad99[0x38b];
 int state; int unk428; int last;
};
extern "C" {
extern char lbl_8045BA94[], lbl_8045BC60[];
extern Hdr lbl_80408ED8;
extern const Block lbl_80408F08;
extern const float lbl_805A2658, lbl_805A265C, lbl_805A2660, lbl_805A2664;
extern IfManager* g_IfMngr;
extern void* g_GameGlobal;
void fn_800F4C34(Task*, const char*, int, int, int);
void fn_8006C6A0(void*);
void* fn_801AB6CC(MEMAllocator*, void*, int);
void fn_800F4F34(Task*, Hdr*, int);
void fn_800F5084(Task*, void*, Block*);
int fn_8004D9E8(void*);
}
extern "C" Task* fn_800F6788(Task* self, int arg) {
 fn_800F4C34(self, lbl_8045BA94, arg, 1, 0x84);
 self->vtable = lbl_8045BC60;
 self->unk428 = -1;
 fn_8006C6A0(self->archive->getData((ARCNodeType)1, 0x77, 0xfffe));
 self->state = 5;
 Hdr a = lbl_80408ED8;
 self->scene = fn_801AB6CC(gfHeapManager::getMEMAllocator((Heaps::HeapType)15), 0, 9);
 self->flags &= ~2;
 fn_800F4F34(self, &a, 2);
 Object_vptr_0* scene = g_IfMngr->scene;
 scene->slot11(scene->fieldE4, self->scene);
 self->active = 1;
 float f1 = lbl_805A2658;
 float f2 = lbl_805A265C;
 int id = 0;
 if (!fn_8004D9E8(g_GameGlobal)) {
  id = 1; f1 = lbl_805A2660; f2 *= lbl_805A2664;
 }
 void* data = self->archive->getData((ARCNodeType)1, id, 0xfffe);
 Block b = lbl_80408F08;
 b.f1 = f1; b.f2 = f2;
 fn_800F5084(self, data, &b);
 self->last = -1;
 return self;
}