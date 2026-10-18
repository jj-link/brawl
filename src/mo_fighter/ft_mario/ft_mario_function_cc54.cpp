#pragma force_active on
struct MarioCopyVector2 { float x; float y; };
extern "C" {
void fn_91_CC54(MarioCopyVector2* dst, const MarioCopyVector2* src) {
    dst->x = src->x;
    dst->y = src->y;
}
}
