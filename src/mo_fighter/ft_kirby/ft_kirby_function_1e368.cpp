#pragma force_active on
struct KirbyState {
    unsigned char padding[8];
    unsigned int flags;
};

extern "C" void fn_96_1E368(KirbyState* state)
{
    state->flags &= ~0x00080000u;
}
