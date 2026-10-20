#pragma force_active on
extern "C" const float lbl_74_rodata_D0;

struct Plankton {
    unsigned char padding[0x174];
    float timer;
};

extern "C" void fn_74_4970(Plankton* self, float delta)
{
    self->timer -= delta;
    if (self->timer < lbl_74_rodata_D0) {
        self->timer = lbl_74_rodata_D0;
    }
}
