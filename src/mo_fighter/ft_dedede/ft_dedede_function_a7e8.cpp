#pragma force_active on
struct Fn117A7E8Owner {
    unsigned char pad[0xc];
    int* counts;
};

extern "C" void fn_117_A7E8(Fn117A7E8Owner* owner, int index) {
    int* counts = owner->counts;
    counts[index] = counts[index] + 1;
}
