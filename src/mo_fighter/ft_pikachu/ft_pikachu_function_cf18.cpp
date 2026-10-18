#pragma force_active on
// Return storage + 0xc when index is 0; otherwise return null.
extern "C" void* fn_98_CF18(char* storage, int index) {
    if (index == 0) return storage + 0xc;
    return 0;
}
