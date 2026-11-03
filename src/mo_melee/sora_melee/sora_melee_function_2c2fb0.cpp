#include <gf/gf_heap_manager.h>
#include <gf/gf_task.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <nw4r/g3d/g3d_scngroup.h>
#pragma force_active on

struct Inner { char pad[0x10]; nw4r::g3d::ScnObj* node; };
struct Task : gfTask {
    char pad40[8];
    nw4r::g3d::ResFile res;
    char pad4c[4];
    nw4r::g3d::ScnGroup* scene;
    Inner* inner;
    int value;
    char pad5c[0x130];
    gfTask* other;
};
struct Manager { char pad[0x14]; nw4r::g3d::ScnGroup* scene; };

extern "C" {
void* fn_27_2B26E8(void*, u32, u32, u32);
void* fn_27_2B2764(void*, u32, u32, u32, u32);
void* fn_27_2B2678(void*, const char*);
int fn_8004D9E8(void*);
Task* fn_27_2C31A0(Task*, void*, void*, void*, void*);
void fn_27_2C3304(Task*, void*, void*);
void fn_27_2C33C4(Task*, void*);
void fn_8006C5A0(void*);
gfTask* fn_8007AD48(gfTask*, void*, u32);
nw4r::g3d::ScnGroup* fn_801AB6CC(MEMAllocator*, u32, u32);
extern void* g_GameGlobal;
extern Manager* g_IfMngr;
extern char lbl_27_data_7B218[];
}

extern "C" void* fn_27_2C2FB0(void* arg0, void* arg1, void* arg2) {
    gfTask* other;
    void* a = fn_27_2B26E8(arg1, 1, 0, 0x14);
    void* b = fn_27_2B2764(arg1, 0, 1, 1, 0x14);
    void* c = fn_27_2B2764(arg1, 1, 1, 0, 0x1E);
    Task* obj = 0;
    if (fn_8004D9E8(g_GameGlobal) == 0) obj = (Task*)1;
    void* d = fn_27_2B2764(arg1, 1, 1, (u32)obj, 0x14);
    void* e = fn_27_2B2678(arg1, lbl_27_data_7B218);
    obj = (Task*)operator new(0x198, (Heaps::HeapType)0xE);
    if (obj) obj = fn_27_2C31A0(obj, arg0, arg1, a, e);
    nw4r::g3d::ResFile::Init(&obj->res);
    nw4r::g3d::ScnGroup* scene = fn_801AB6CC(gfHeapManager::getMEMAllocator((Heaps::HeapType)0x1F), 0, 1);
    fn_8006C5A0(c);
    obj->unk2C_b1 = false;
    obj->scene = 0;
    obj->inner = 0;
    obj->value = 0;
    fn_27_2C3304(obj, &obj->res, arg2);
    obj->scene = scene;
    scene->Insert(scene->sceneItemsCount, obj->inner->node);
    fn_27_2C33C4(obj, d);
    g_IfMngr->scene->Insert(g_IfMngr->scene->sceneItemsCount, (nw4r::g3d::ScnObj*)scene);
    other = (gfTask*)operator new(0xA0, (Heaps::HeapType)0x1F);
    if (other) other = fn_8007AD48(other, b, 0x1F);
    other->init();
    obj->other = other;
    return obj;
}