#include <types.h>
#include <nw4r/g3d/g3d_resmdl.h>
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
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual int slot11(u32, int);
    virtual void slot12(u32);

    char pad[0xe0];
    u32 count;
    char* model;
    u32* nodes;
};

extern "C" int fn_801B4CB0(Object_vptr_0* self, int arg1, u32 node) {
    if (self->slot11(self->count, arg1) == 0) {
        return 0;
    }
    u32 index = self->count - 1;
    nw4r::g3d::ResMdl mdl(*(void**)(self->model + 0xe8));
    int success;
    if (node < mdl.GetResNodeNumEntries() && index < self->count) {
        self->nodes[index] = node;
        success = 1;
    } else {
        success = 0;
    }
    if (success == 0) {
        if (self->count != 0) {
            self->slot12(self->count - 1);
        }
        return 0;
    }
    return 1;
}
