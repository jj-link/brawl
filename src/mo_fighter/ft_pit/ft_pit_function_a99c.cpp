#pragma force_active on
struct Work { void* pad[7]; unsigned int* flags; };

extern "C" bool fn_112_A99C(const Work* work, unsigned int mask, int index) {
    return (work->flags[index] & mask) != 0;
}
