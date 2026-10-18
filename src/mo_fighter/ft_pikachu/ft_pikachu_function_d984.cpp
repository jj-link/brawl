#pragma force_active on
// Return the sub-object at +0xc only when the selector is zero.
extern "C" void* fn_98_D984(char* obj, int selector) {
    if (selector == 0) return obj + 0xc;
    return 0;
}
