#pragma force_active on
struct Matrix {
    float m[8];
};

struct Scale {
    float x, y;
};

extern "C" {
extern const float lbl_805A33CC;

void fn_801AA390(Matrix* dst, const Scale* scale) {
    dst->m[0] = dst->m[0] * scale->x;
    dst->m[1] = dst->m[1] * scale->x;
    dst->m[2] = dst->m[2] * scale->x;
    dst->m[3] = lbl_805A33CC + scale->x * (dst->m[3] - lbl_805A33CC);
    dst->m[4] = dst->m[4] * scale->y;
    dst->m[5] = dst->m[5] * scale->y;
    dst->m[6] = dst->m[6] * scale->y;
    dst->m[7] = lbl_805A33CC + scale->y * (dst->m[7] - lbl_805A33CC);
}
}
