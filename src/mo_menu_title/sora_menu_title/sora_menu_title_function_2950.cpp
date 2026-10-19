#pragma force_active on
extern "C" {
extern const float lbl_24_rodata_40;
void fn_800B753C(void*, float);

void fn_24_2950(void* self) {
    fn_800B753C(*(void**)((char*)self + 0x54), lbl_24_rodata_40);
}
}
