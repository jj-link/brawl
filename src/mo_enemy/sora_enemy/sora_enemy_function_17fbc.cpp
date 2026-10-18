#pragma force_active on
extern "C" {
    extern float lbl_41_rodata_C3C;
    extern float lbl_41_rodata_C48;
}

typedef struct { int x, y; } UnkPt;
typedef struct { float a, b; } UnkVec;

extern "C" {
    UnkPt fn_41_17EB0(int a, int b);
    float fn_41_10830(UnkPt* p);
    float fn_41_108AC(UnkPt* p, UnkVec* v);
}

extern "C" int fn_41_17FBC(int a, int b) {
    UnkVec v;
    UnkPt p1, p2;
    v.a = lbl_41_rodata_C48;
    v.b = lbl_41_rodata_C3C;
    UnkPt r = fn_41_17EB0(a, b);
    p1 = r;
    p2 = r;
    float res1 = fn_41_10830(&p2);
    if (res1 <= lbl_41_rodata_C3C) {
        return -1;
    }
    float res2 = fn_41_108AC(&p2, &v);
    if (res2 > lbl_41_rodata_C3C) {
        return 2;
    } else if (res2 < lbl_41_rodata_C3C) {
        return 3;
    } else {
        return -1;
    }
}
