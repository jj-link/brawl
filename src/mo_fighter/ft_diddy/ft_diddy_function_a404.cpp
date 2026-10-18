#pragma force_active on
typedef unsigned int u32;

struct CounterOwner {
    char pad[0xc];
    int *counts;
};

extern "C" void fn_115_A404(CounterOwner *self, u32 index) {
    self->counts[index]++;
}
