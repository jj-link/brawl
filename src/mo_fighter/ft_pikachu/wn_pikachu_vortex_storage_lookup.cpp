// The four embedded elements are 0x2184 bytes apart, beginning at 0x18.
// Reject every index outside the original four-element range.
extern "C" void* fn_98_19088(char* storage, int index) {
    if (index == 3) return storage + 0x64a4;
    if (index == 2) return storage + 0x4320;
    if (index == 1) return storage + 0x219c;
    if (index == 0) return storage + 0x18;
    return 0;
}
