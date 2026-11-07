#include <gr/gr_yakumono.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7(int, void*);
};

struct CallbackData {
    char pad[4];
    int* node;
};

struct grMadein {
    char pad0[0x44];
    nw4r::g3d::ScnMdlSimple** model;
    char pad48[0x88];
    CallbackData callback;
    char padD8[0xa4];
    int fields[9];
};

extern "C" void startup__8grMadeinFP9gfArchiveUlUl(grMadein* self, gfArchive* archive, u32 id, u32 layer) {
    CallbackData* callback = &self->callback;
    ((grYakumono*)self)->grYakumono::startup(archive, id, (gfSceneRoot::LayerType)layer);
    nw4r::g3d::ScnMdlSimple* model = *self->model;
    if (model) {
        Object_vptr_0* obj = (Object_vptr_0*)model;
        obj->slot7(1, &self->fields[0]);
        obj->slot7(2, &self->fields[1]);
        obj->slot7(3, &self->fields[2]);
        obj->slot7(4, &self->fields[3]);
        obj->slot7(5, &self->fields[4]);
        obj->slot7(6, &self->fields[5]);
        obj->slot7(7, &self->fields[6]);
        obj->slot7(8, &self->fields[7]);
        obj->slot7(9, &self->fields[8]);
        model->m_calcWorldCallBack = (nw4r::g3d::ICalcWorldCallBack*)callback;
        model->EnableScnMdlCallbackTiming(1);
        model->m_nodeIndex = *callback->node;
    }
}