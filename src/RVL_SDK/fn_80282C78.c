#pragma force_active on
typedef struct { float m[12]; } Mtx34;
void fn_80282C78(Mtx34 *dst, const Mtx34 *src) {
    dst->m[0] = src->m[0];
    dst->m[5] = src->m[5];
    dst->m[10] = src->m[10];
    dst->m[3] = 0.0f;
    dst->m[7] = 0.0f;
    dst->m[11] = 0.0f;
    dst->m[1] = src->m[4];
    dst->m[4] = src->m[1];
    dst->m[2] = src->m[8];
    dst->m[8] = src->m[2];
    dst->m[6] = src->m[9];
    dst->m[9] = src->m[6];
}