#pragma force_active on
struct NessCounterOwner {
    char pad[0xC];
    int* counters;
};

extern "C" void fn_101_D47C(NessCounterOwner* self, int index) {
    self->counters[index]++;
}
