#pragma force_active on

extern "C" float fn_801622A0(float);

extern const float lbl_805A2D60;
extern const float lbl_805A2D64;
extern const float lbl_805A2D68;

struct Vec {
    float x, y, z;
};

struct Mat {
    float m[3][4];
};

inline float root(float x) {
    if (x <= lbl_805A2D60)
        return lbl_805A2D60;
    return x * fn_801622A0(x);
}

extern "C" void fn_8016F32C(Mat* out, const Vec* v) {
    float z = v->z;
    float r = root(lbl_805A2D64 - z * z);
    float s, c;

    if (r > lbl_805A2D68) {
        c = v->y / r;
        s = v->x / -r;
    } else {
        s = lbl_805A2D60;
        c = lbl_805A2D64;
    }

    out->m[0][0] = c;
    out->m[0][1] = v->x;
    out->m[0][2] = z * s;
    out->m[0][3] = lbl_805A2D60;
    out->m[1][0] = s;
    out->m[1][1] = v->y;
    out->m[1][2] = -c * z;
    out->m[1][3] = lbl_805A2D60;
    out->m[2][0] = lbl_805A2D60;
    out->m[2][1] = v->z;
    out->m[2][2] = r;
    out->m[2][3] = lbl_805A2D60;
}
