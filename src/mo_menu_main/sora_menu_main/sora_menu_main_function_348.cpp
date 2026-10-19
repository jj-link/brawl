#pragma force_active on
extern "C" void fn_800B96E8(void* p, int v);

extern "C" void* fn_2_348(void* p) {
    fn_800B96E8(p, 0xff);
    return p;
}
