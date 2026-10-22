#pragma force_active on
struct Vec { float x, y, z; };
struct Quat { float x, y, z, w; };
extern "C" {
double sin(double);
double cos(double);
void fn_8003DEE0(Vec* out, const Vec* p);
extern const float lbl_805A1740;
}

extern "C" void fn_8003F8FC(Quat* out, const Vec* p, float angle) {
    float s = sin(lbl_805A1740 * angle);
    float c = cos(lbl_805A1740 * angle);
    Vec v;
    fn_8003DEE0(&v, p);
    out->x = v.x * s;
    out->y = v.y * s;
    float z = v.z * s;
    out->w = c;
    out->z = z;
}
