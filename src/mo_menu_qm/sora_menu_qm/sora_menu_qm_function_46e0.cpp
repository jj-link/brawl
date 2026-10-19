#pragma force_active on
extern "C" {
void fn_800B96E8(void* p, int v);

void* fn_4_46E0(void* self) {
    fn_800B96E8((char*)self + 4, 0xff);
    return self;
}
}
