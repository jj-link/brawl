#pragma force_active on
struct ftLucarioCountOwner {
    char pad[0xC];
    int* counts;
};

extern "C" void fn_118_A4C0(ftLucarioCountOwner* self, int index) {
    self->counts[index]--;
}
