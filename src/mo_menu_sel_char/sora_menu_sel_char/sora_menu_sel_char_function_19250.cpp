#include <mu/mu_object.h>
#pragma force_active on
struct Menu {
    unsigned char pad0[0x144];
    MuObject* object;
    unsigned char pad148[0x68];
    int frame;
};
extern "C" void fn_10_19250(Menu* self) {
    self->object->setFrameMatCol((float)self->frame);
}