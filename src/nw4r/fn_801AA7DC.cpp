#pragma force_active on

struct Matrix {
    float m[8];
};

struct Params {
    float x, y, z, w, v;
};

extern const float lbl_805A33CC;

extern "C" void fn_801AA7DC(Matrix* a, const Params* b) {
    a->m[0] = a->m[0] * b->x;
    a->m[1] = a->m[1] * b->x;
    a->m[2] = a->m[2] * b->x;
    a->m[3] = lbl_805A33CC + b->x * ((a->m[3] - b->w) - lbl_805A33CC);
    a->m[4] = a->m[4] * b->y;
    a->m[5] = a->m[5] * b->y;
    a->m[6] = a->m[6] * b->y;
    a->m[7] = a->m[7] * (lbl_805A33CC + b->y * ((a->m[7] + b->v) - lbl_805A33CC));
}
