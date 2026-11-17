#pragma force_active on
extern "C" {
double fn_80400AB8(double);
void fn_8003E3BC(void*, void*, void*);
void fn_8003DE70(void*);
}

extern const float lbl_805A1418;
extern const float lbl_805A142C;
extern const float lbl_805A1430;

struct Cam {
    char pad0[0x30];
    float mtx[12];
    char pad1[0xD8 - 0x60];
    float fov;
    char padDC[8];
    float aspect;
    char padE8[0x11C - 0xE8];
    float w;
    float h;
};

extern "C" void fn_80019E88(Cam* cam, float* out, float farg0, float farg1) {
    float scale = lbl_805A1430 * (float)fn_80400AB8(lbl_805A142C * cam->fov);
    float sx = scale * cam->aspect;
    out[0] = (sx * (farg0 - lbl_805A142C * cam->w)) / cam->w;
    out[1] = -((scale * (farg1 - lbl_805A142C * cam->h)) / cam->h);
    out[2] = lbl_805A1418;
    fn_8003E3BC(cam->mtx, out, out);
    fn_8003DE70(out);
}
