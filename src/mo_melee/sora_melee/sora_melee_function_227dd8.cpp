#pragma force_active on
struct Vec3f { float x, y, z; };
struct Vec2f {
    union { struct { float x, y; }; unsigned int words[2]; };
    Vec2f() {}
    Vec2f(const Vec3f& v) : x(v.x), y(v.y) {}
};
inline void set(Vec3f* dst, const Vec2f& v, float c) {
    float a, b;
    b = v.y;
    a = v.x;
    dst->x = a;
    dst->y = b;
    dst->z = c;
}
struct Segment {
    Vec2f a, b;
    Segment(const Vec2f& aa, const Vec2f& bb) { a = aa; b = bb; }
};
struct RayQuery {
    unsigned char pad0[0x12];
    unsigned char mode;
    unsigned char pad13[5];
    Vec2f normal;
    Vec2f point;
    unsigned char pad28[0x14];
    int index;
    bool flag1, flag2;
    unsigned char pad42[2];
};
extern "C" {
extern const float lbl_27_rodata_36F0;
void fn_8013804C(RayQuery*);
void fn_8013807C(RayQuery*, int);
int fn_80138348(RayQuery*, const Segment*);
int stRayCheck__FP5Vec3fP5Vec3fPiP5Vec3fP5Vec3fbbUc(Vec3f* start, Vec3f* end, int* index, Vec3f* point, Vec3f* normal, bool flag2, bool flag1, unsigned char mode) {
    RayQuery query;
    fn_8013804C(&query);
    Segment segment((Vec2f(*start)), (Vec2f(*end)));
    query.mode = mode;
    query.flag1 = flag1;
    query.flag2 = flag2;
    int result = fn_80138348(&query, &segment);
    if (result) {
        *index = query.index;
        set(point, query.point, lbl_27_rodata_36F0);
        set(normal, query.normal, lbl_27_rodata_36F0);
    }
    fn_8013807C(&query, -1);
    return result;
}
}
