struct NessNullStick { float x; float y; };
// The trigger pair is returned as raw words in r3/r4. Zero bits are +0.0f
// for both trigger values and avoid changing this POD return ABI.
struct NessNullTrigger { unsigned int left; unsigned int right; };
extern "C" const float lbl_101_rodata_A8;

extern "C" int fn_101_16174(void*) { return -1; }

// IpNull's original rumble and update methods deliberately do nothing.
extern "C" void fn_101_1617C(void*, unsigned int) {}
extern "C" void fn_101_16180(void*, int, int) {}
extern "C" void fn_101_16184(void*) {}
extern "C" void fn_101_16188(void*) {}
extern "C" void fn_101_1618C(void*, unsigned int, unsigned int, int, unsigned char) {}

extern "C" NessNullTrigger fn_101_16190(void*) {
    NessNullTrigger trigger = {0, 0};
    return trigger;
}
extern "C" unsigned int fn_101_161AC(void*) { return 0; }
extern "C" NessNullStick fn_101_161B4(void*) {
    NessNullStick stick = {lbl_101_rodata_A8, lbl_101_rodata_A8};
    return stick;
}
extern "C" NessNullStick fn_101_161D8(void*) {
    NessNullStick stick = {lbl_101_rodata_A8, lbl_101_rodata_A8};
    return stick;
}
extern "C" void fn_101_161FC(void*) {}
