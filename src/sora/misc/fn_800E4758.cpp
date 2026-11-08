#include <mu/mu_object.h>
#pragma force_active on
struct Slot {
    unsigned char frame;
    char pad[3];
    int state;
    MuObject* object;
};
struct Menu {
    char pad0[0xF4];
    void* resource;
    char pad1[0x170];
    Slot slots[3];
    char pad2[0x338];
    int values[3];
};
inline int findSlot(Menu* self) {
    for (int i = 0; i < 3; ++i) {
        if (self->slots[i].state == 0) return i;
    }
    return -1;
}
extern "C" {
void fn_801B4CB0(void*, void*, int);
int fn_800B5854(MuObject*, int, int, int, int);
int fn_800E4758(Menu* self, unsigned char frame) {
    int index = findSlot(self);
    if (index < 0) return 0;
    MuObject* object = self->slots[index].object;
    fn_801B4CB0(self->resource, object->m_sceneModel, self->values[index]);
    object->setFrameVisible((float)frame);
    fn_800B5854(object, 0, 0x11, 1, 0);
    self->slots[index].state = 2;
    self->slots[index].frame = frame;
    return 1;
}
}