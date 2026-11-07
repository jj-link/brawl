#include <mt/mt_matrix.h>

#pragma force_active on

struct Owner {
    char pad[0x50];
    Matrix matrix;
};

struct Object {
    char pad[0xD4];
    Owner* owner;
};

extern "C" void fn_27_26DDB0(Object* self, Matrix* out) {
    Owner* owner = self->owner;
    if (owner) {
        *out = owner->matrix;
    } else {
        static_cast<Matrix*>(out)->setIdentity();
    }
}
