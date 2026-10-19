#pragma force_active on
extern "C" {
extern const float lbl_101_rodata_8;
struct NessZeroVec { float x; float y; };
void* fn_101_FE5C(void*, const void*);
}

extern "C" void fn_101_FE24(void* self) {
    NessZeroVec zero = {lbl_101_rodata_8, lbl_101_rodata_8};
    fn_101_FE5C(reinterpret_cast<char*>(self) + 8, &zero);
}
