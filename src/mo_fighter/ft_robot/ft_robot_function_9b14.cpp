#pragma force_active on
typedef struct Holder {
    char pad[0xc];
    int *counts;
} Holder;

extern "C" void fn_120_9B14(Holder *self, int index)
{
    self->counts[index]++;
}
