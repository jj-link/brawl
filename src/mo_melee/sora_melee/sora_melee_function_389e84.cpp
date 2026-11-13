#include <gf/gf_task.h>
#include <gf/gf_heap_manager.h>
#include <if/if_mngr.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scngroup.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <types.h>
#pragma force_active on

struct FinalSceneTask {
    gfTask task;
    void* resource;
    unsigned long resourceState;
    nw4r::g3d::ScnGroup* scene;
    MuObject* models[1];
    void* sceneObjects[1];
};

struct FinalManagerView {
    unsigned char reserved[0x14];
    nw4r::g3d::ScnGroup* scene;
};

extern "C" {
extern char lbl_27_data_994E8[];
extern char lbl_27_data_994F8[];
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
gfTask* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(gfTask*, const char*, gfTask::Category, int, int, bool);
nw4r::g3d::ScnGroup* fn_801AB6CC(MEMAllocator*, void*, int);
void fn_27_38A09C(void*, void*, Heaps::HeapType, int);
}

extern "C" FinalSceneTask* fn_27_389E84(void* data, Heaps::HeapType heap, int priority) {
    FinalSceneTask* self = (FinalSceneTask*)__nw__FUlQ25Heaps8HeapType(sizeof(FinalSceneTask), heap);
    if (self) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(&self->task, lbl_27_data_994E8, gfTask::Category_Info, 14, 6, true);
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(&self->task) + 0x3c) = lbl_27_data_994F8;
        self->resource = data;
        self->resourceState = 0;
    }
    nw4r::g3d::ResFile::Init(&self->resource);
    nw4r::g3d::ScnGroup* scene = fn_801AB6CC(gfHeapManager::getMEMAllocator(heap), 0, 1);
    self->task.unk2C_b1 = 0;
    self->scene = 0;
    self->models[0] = 0;
    self->sceneObjects[0] = 0;
    fn_27_38A09C(self, &self->resource, heap, priority);
    self->scene = scene;
    scene->Insert(scene->sceneItemsCount, self->models[0]->m_sceneModel);
    nw4r::g3d::ScnGroup* parent = reinterpret_cast<FinalManagerView*>(g_IfMngr)->scene;
    parent->Insert(parent->sceneItemsCount, reinterpret_cast<nw4r::g3d::ScnObj*>(scene));
    return self;
}
