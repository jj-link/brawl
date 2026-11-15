#include <gf/gf_task.h>
#include <if/if_mngr.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scngroup.h>
#include <nw4r/g3d/g3d_obj.h>
#include <types.h>
#pragma force_active on

struct FinalSceneTask {
    gfTask task;
    void* resource;
    unsigned long resourceState;
    nw4r::g3d::ScnGroup* scene;
    MuObject* models[1];
    nw4r::g3d::G3dObj* sceneObjects[1];
};

struct FinalManagerView {
    unsigned char reserved[0x14];
    nw4r::g3d::ScnGroup* scene;
};

extern "C" {
extern char lbl_27_data_994F8[];
gfTask* __dt__6gfTaskFv(gfTask*, short);
}

extern "C" FinalSceneTask* fn_27_389FB0(FinalSceneTask* self, short deleting) {
    if (self) {
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(&self->task) + 0x3c) = lbl_27_data_994F8;
        for (int i = 0; i < 1; ++i) {
            if (self->sceneObjects[i]) {
                self->sceneObjects[i]->Destroy();
                self->sceneObjects[i] = 0;
            }
        }
        for (int i = 0; i < 1; ++i) {
            if (self->models[i]) {
                delete self->models[i];
                self->models[i] = 0;
            }
        }
        if (self->scene) {
            nw4r::g3d::ScnGroup* parent = reinterpret_cast<FinalManagerView*>(g_IfMngr)->scene;
            if (parent) parent->Remove(reinterpret_cast<nw4r::g3d::ScnObj*>(self->scene));
            reinterpret_cast<nw4r::g3d::G3dObj*>(self->scene)->Destroy();
        }
        __dt__6gfTaskFv(&self->task, 0);
        if (deleting > 0) operator delete(self);
    }
    return self;
}
