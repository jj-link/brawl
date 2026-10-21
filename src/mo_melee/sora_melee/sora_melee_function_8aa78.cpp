#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_BD0;
extern const float lbl_27_rodata_BD4;
}

struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;

    Vec3() {}

    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }

    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}

    Vec3& operator=(const Vec3& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
};

struct Object {
    char pad[8];
    Vec3 a, b, c, d, e;
};

extern "C" void fn_27_8AA78(Object* p, int unused, const Vec2* v) {
    Vec3 a, e, d, c, b;

    a.set(v->x, v->y, lbl_27_rodata_BD0);
    p->a = a;

    b.set(lbl_27_rodata_BD0, lbl_27_rodata_BD0, lbl_27_rodata_BD0);
    p->b = b;

    c.set(lbl_27_rodata_BD0, lbl_27_rodata_BD0, lbl_27_rodata_BD0);
    p->c = c;

    d.set(lbl_27_rodata_BD0, lbl_27_rodata_BD0, lbl_27_rodata_BD0);
    p->d = d;

    e.set(lbl_27_rodata_BD4, lbl_27_rodata_BD4, lbl_27_rodata_BD4);
    p->e = e;
}
