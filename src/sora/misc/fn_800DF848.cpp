#pragma force_active on
struct Ret { float x, y, z; };
struct Vec { float x, y, z; Vec(const Ret& v) : x(v.x), y(v.y), z(v.z) {} };
struct Obj { char pad[4]; float m[3][4]; char param[16]; int mode; };
extern "C" void fn_800DB674(void*, float*);
extern "C" Ret fn_800DF95C(float*, void*);
extern "C" void fn_8003E9B4(float*, float);
extern "C" void fn_8003E388(void*, float*);
extern char lbl_8049E0A0[];
extern "C" void fn_800DF848(Obj* self) {
    switch (self->mode) {
    case 0:
        fn_800DB674(self->param, &self->m[0][0]);
        break;
    case 3:
        fn_800DB674(self->param, &self->m[0][0]);
        break;
    case 1: {
        float angle;
        Vec v = fn_800DF95C(&angle, self->param);
        fn_8003E9B4(&self->m[0][0], angle);
        self->m[0][3] = v.x;
        self->m[1][3] = v.y;
        self->m[2][3] = v.z;
        break;
    }
    case 2: {
        Vec v = fn_800DF95C(0, self->param);
        fn_8003E388(lbl_8049E0A0, &self->m[0][0]);
        self->m[0][3] = v.x;
        self->m[1][3] = v.y;
        self->m[2][3] = v.z;
        break;
    }
    }
}