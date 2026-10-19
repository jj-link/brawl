#include <gr/ground.h>
#pragma force_active on

extern "C" void processAnim__6GroundFv(void*);
extern "C" char lbl_52_data_1028[];
extern "C" char lbl_52_data_1030[];

struct Object {
    unsigned char pad0[0x6C];
    unsigned char flags;
    unsigned char pad6D[0x5B];
    unsigned char enabled;
    unsigned char padC9[0xA3];
    unsigned char* data;
};

extern "C" void fn_52_4E70(Object* self) {
    self->flags &= ~2;
    processAnim__6GroundFv(self);

    if (self->enabled && self->data) {
        ((Ground*)self)->getNodeMatrix(
            (Matrix*)(self->data + 0x150), 0, lbl_52_data_1028);
        ((Ground*)self)->getNodeMatrix(
            (Matrix*)(self->data + 0x300), 0, lbl_52_data_1030);
    }
}
