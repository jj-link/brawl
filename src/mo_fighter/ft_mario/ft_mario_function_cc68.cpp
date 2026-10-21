#pragma force_active on
struct MarioCopyVector2 {
    float x;
    float y;
};

extern "C" {
extern const float lbl_91_rodata_8;
extern const float lbl_91_rodata_10;
MarioCopyVector2* fn_91_CC54(MarioCopyVector2* dst, const MarioCopyVector2* src);

void fn_91_CC68(unsigned char* self) {
    MarioCopyVector2 a;
    MarioCopyVector2 b;
    a.x = lbl_91_rodata_8;
    a.y = lbl_91_rodata_8;
    MarioCopyVector2* r = fn_91_CC54(reinterpret_cast<MarioCopyVector2*>(self + 0x20), &a);
    r = fn_91_CC54(reinterpret_cast<MarioCopyVector2*>(self + 0x10), r);
    fn_91_CC54(reinterpret_cast<MarioCopyVector2*>(self + 0x8), r);
    b.x = lbl_91_rodata_10;
    b.y = lbl_91_rodata_10;
    r = fn_91_CC54(reinterpret_cast<MarioCopyVector2*>(self + 0x28), &b);
    fn_91_CC54(reinterpret_cast<MarioCopyVector2*>(self + 0x18), r);
    self[0x31] = 0;
    self[0x30] = 0;
    self[0x32] = 1;
}
}
