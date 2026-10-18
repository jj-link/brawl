#pragma force_active on
// Return the sub-object at offset 0xc when the flag argument is zero, otherwise null.
extern "C" void* fn_98_D44C(char* base, int flag) {
    if (flag == 0) return base + 0xc;
    return 0;
}
