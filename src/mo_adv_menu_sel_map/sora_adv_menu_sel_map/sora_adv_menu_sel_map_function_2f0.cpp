#pragma force_active on
extern "C" {
void* fn_800B96E8(void* p, unsigned int v);

void* fn_31_2F0(void* p) {
    fn_800B96E8(p, 0xff);
    return p;
}
}
