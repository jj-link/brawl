#pragma force_active on
extern "C" {
extern float lbl_41_rodata_C38[];
void fn_8003DBA8(void*);
float fn_8003DDD0(void*, void*);

struct Vec2 { float x, y; };

float fn_41_15A00(float angle, Vec2* vec) {
    float* base = lbl_41_rodata_C38;
    Vec2 local;
    local.x = angle;
    local.y = base[1];
    fn_8003DBA8(&local);
    fn_8003DBA8(vec);
    float result = fn_8003DDD0(vec, &local);
    if (vec->y >= base[1])
        return base[2] * result;
    return base[3] - base[2] * result;
}
}
