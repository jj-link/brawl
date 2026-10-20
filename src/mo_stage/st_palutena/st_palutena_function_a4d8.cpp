#include <gr/ground.h>
#pragma force_active on

struct Object : public Ground {
    char pad[0xbc];
    char* data;
    char pad2[0x40];
    u32 value;
};

extern "C" void fn_67_A4D8(Object* self) {
    self->Ground::processAnim();
    if (self->data) {
        self->getNodePosition((Vec3f*)(self->data + 0xc), 0, self->value);
    }
}
