#pragma force_active on
struct Plankton {
    unsigned char padding[8];
    unsigned int flags;
};

extern "C" void fn_74_6BBC(Plankton* self)
{
    self->flags &= ~0x00080000u;
}
