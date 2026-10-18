#pragma force_active on
struct Vec3f {
    float x, y, z;

    Vec3f& operator=(const Vec3f& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
};

extern "C" {
extern void* g_ftManager;

bool fn_27_239664(int id, Vec3f* out, int kind);

bool fn_27_2398D8(int id, Vec3f* out) {
    return fn_27_239664(id, out, 2);
}
}
