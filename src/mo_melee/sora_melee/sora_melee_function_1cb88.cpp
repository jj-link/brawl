#pragma force_active on
typedef float f32;

extern const f32 lbl_27_rodata_340;

extern "C" bool fn_27_1CB88(const void* p) {
    return *reinterpret_cast<const f32*>(
               reinterpret_cast<const char*>(p) + 0x5C) <
           lbl_27_rodata_340;
}
