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
struct CopyF0 { int data[60]; };
struct Copy60 { int a[3]; float x; int b; float y; int c; float sx, sy; int rest[15]; };
struct Task {
 char pad0[0x2c]; unsigned char flags; char pad2d[0xf];
 void* vtable; gfArchive* archive; char pad44[0x4c];
 void* scene; char pad94[4]; unsigned char active; char pad99[0x38b]; int state;
};
extern "C" {
extern char lbl_8045BA68[], lbl_8045BD28[];
extern const CopyF0 lbl_80408D88;
extern const Copy60 lbl_80408E78;
extern const float lbl_805A2610, lbl_805A2640, lbl_805A2644, lbl_805A2648, lbl_805A264C, lbl_805A2650, lbl_805A2654;
extern IfManager* g_IfMngr;
extern void* g_GameGlobal;
void fn_800F4C34(Task*, const char*, int, int, int);
void fn_8006C6A0(void*);
void* fn_801AB6CC(MEMAllocator*, void*, int);
void fn_800F4F34(Task*, CopyF0*, int);
void fn_800F5084(Task*, void*, Copy60*);
int fn_8004D9E8(void*);
}
extern "C" Task* fn_800F609C(Task* self, int arg) {
 fn_800F4C34(self, lbl_8045BA68, arg, 1, 0x84);
 self->vtable = lbl_8045BD28;
 fn_8006C6A0(self->archive->getData((ARCNodeType)1, 0x77, 0xfffe));
 self->state = 5;
 CopyF0 a = lbl_80408D88;
 self->scene = fn_801AB6CC(gfHeapManager::getMEMAllocator((Heaps::HeapType)15), 0, 9);
 self->flags &= ~2;
 fn_800F4F34(self, &a, 10);
 Object_vptr_0* scene = g_IfMngr->scene;
 scene->slot11(scene->fieldE4, self->scene);
 self->active = 1;
 float sx = lbl_805A2640;
 float sy = lbl_805A2644;
 float y = lbl_805A2610;
 int id = 0;
 if (!fn_8004D9E8(g_GameGlobal)) {
  id = 1;
  sy *= lbl_805A2648;
  y += lbl_805A264C;
 }
 void* data = self->archive->getData((ARCNodeType)1, id, 0xfffe);
 Copy60 b = lbl_80408E78;
 b.sx = sx;
 b.sy = sy;
 b.x = lbl_805A2650 + y;
 b.y = lbl_805A2654 + y;
 fn_800F5084(self, data, &b);
 return self;
}