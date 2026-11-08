#include <gf/gf_heap_manager.h>
#include <nw4r/g3d/g3d_resmdl.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <mu/mu_object.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(int);
 char pad[0xE0]; int count;
};
struct SourceInner { char pad[0xE8]; void* mdl; };
struct Source { char pad[0xE8]; SourceInner* inner; };
struct Task { char pad[0x40]; MuObject* model; char pad2[0x10]; Object_vptr_0* scene; Source* source; int node; int count; int mode; };
extern unsigned char lbl_80408540[];
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
Task* fn_800DA354(void*);
void fn_800DA4A8(void*, void*, int, int, int, int);
int fn_800DA81C(void*, int, int, int, int, int);
void fn_801B4CB0(void*, void*, int);
nw4r::g3d::ResNodeData* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);
}
inline int clampCount(int count) {
 int n = 1;
 if (count > 1) n = count;
 int limit = 3;
 if (n < 3) limit = n;
 return limit;
}
extern "C" Task* fn_800DA15C(int count, int priority, Source* source, const char* name, int draw, int heap, Heaps::HeapType allocator) {
 int node;
 Task* task = (Task*)__nw__FUlQ25Heaps8HeapType(0x68, heap);
 if (task) task = fn_800DA354(task);
 int limit = clampCount(count);
 node = 0;
 nw4r::g3d::ResMdl mdl;
 task->count = limit;
 task->source = source;
 mdl = nw4r::g3d::ResMdl(source->inner->mdl);
 nw4r::g3d::ResNodeData* res = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&mdl, name);
 if (res) node = res->m_nodeIndex;
 task->node = node;
 fn_800DA4A8(task, lbl_80408540, 2, priority, draw, allocator);
 task->scene = (Object_vptr_0*)nw4r::g3d::ScnMdl::Construct(gfHeapManager::getMEMAllocator(allocator), 0, 4, task->model->m_sceneModel);
 Object_vptr_0* scene = task->scene;
 int c;
 while (c = scene->count) {
  if (c == 0) continue;
  scene->slot12(c - 1);
 }
 float f;
 if (task->mode == 0) {
  fn_800DA81C(task, 0, task->count, 1, 0, 1);
  f = (float)(task->count - 1);
 } else {
  fn_800DA81C(task, 0, 2, 0, 0, 1);
  fn_800DA81C(task, 0, 2, 1, 2, 3);
  f = (float)(task->count + 2);
 }
 task->model->setFrameNode(f);
 fn_801B4CB0(task->source, task->scene, task->node);
 return task;
}