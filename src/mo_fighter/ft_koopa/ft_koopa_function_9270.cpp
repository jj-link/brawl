#pragma force_active on
typedef struct CounterOwner
{
    char pad[0xc];
    int *counts;
} CounterOwner;

extern "C" void fn_102_9270(CounterOwner *self, unsigned int index)
{
    self->counts[index]++;
}
