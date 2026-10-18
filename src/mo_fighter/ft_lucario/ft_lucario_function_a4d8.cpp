#pragma force_active on
struct FtLucarioCounterOwner {
    char pad[0xC];
    int *counts;
};

extern "C" void fn_118_A4D8(FtLucarioCounterOwner *self, int index) {
    self->counts[index]++;
}
