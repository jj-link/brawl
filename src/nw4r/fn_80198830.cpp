#pragma force_active on
extern "C" void fn_80198830(int* dest, int* src, int mask) {
    *dest = mask & *src;
}
