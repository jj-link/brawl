#pragma force_active on
#pragma push
#pragma opt_propagation off

extern "C" void fn_801ECD70(void*, int, void*);
extern "C" void fn_80162C48(void*, void*, void*);
extern "C" void fn_8003E388(void*, void*);

struct Globals8049 {
    unsigned char first[0x30];
};
extern Globals8049 lbl_8049E030;
extern float lbl_805A02B8[2];
extern const float lbl_805A2344;

struct Vec3 { float x, y, z; };

extern "C" void fn_800DB674(int arg0, float* arg1) {
    Globals8049* base = &lbl_8049E030;
    unsigned char (Globals8049::*first)[0x30] = &Globals8049::first;
    Vec3 vec;
    Vec3 v;
    Vec3 out;
    fn_801ECD70(&(base->*first), arg0, &vec);
    fn_80162C48(&v, (unsigned char*)base + 0x30, &vec);
    out.x = v.x * lbl_805A02B8[0];
    out.y = v.y * lbl_805A02B8[1];
    out.z = lbl_805A2344;
    fn_8003E388((unsigned char*)base + 0x70, arg1);
    arg1[3] = out.x;
    arg1[7] = out.y;
    arg1[11] = out.z;
}

#pragma pop
