#pragma force_active on
extern "C" void fn_800B96E8(void* p, int v);

extern "C" void* fn_32_2B0(void* p) {
    fn_800B96E8(p, 0xff);
    return p;
}
