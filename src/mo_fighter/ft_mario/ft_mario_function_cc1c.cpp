#pragma force_active on
struct MarioCopyVector2 { float x; float y; };

extern "C" {
extern const float lbl_91_rodata_8;
void fn_91_CC54(MarioCopyVector2* dst, const MarioCopyVector2* src);

void fn_91_CC1C(unsigned char* self) {
    MarioCopyVector2 v;
    v.x = lbl_91_rodata_8;
    v.y = lbl_91_rodata_8;
    fn_91_CC54(reinterpret_cast<MarioCopyVector2*>(self + 0x8), &v);
}
}
