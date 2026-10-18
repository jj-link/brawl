#pragma force_active on
// Return the embedded element at offset 0xc when index is 0; otherwise null.
extern "C" void* fn_98_E158(char* base, int index) {
    if (index == 0) return base + 0xc;
    return 0;
}
