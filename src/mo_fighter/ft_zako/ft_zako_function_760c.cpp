#pragma force_active on
typedef struct Holder {
    char pad[0xc];
    int *counts;
} Holder;

extern "C" void fn_126_760C(Holder *self, unsigned int index)
{
    self->counts[index]++;
}
