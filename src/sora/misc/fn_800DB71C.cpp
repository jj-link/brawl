#pragma force_active on

extern "C" {
void fn_801ECD70(void*, void*, void*);
void fn_80162C48(float*, void*, void*);

extern unsigned char lbl_8049E030[];
extern unsigned char lbl_8049E060[];

struct Pair {
    float a;
    float b;
};

extern Pair lbl_805A02C0;
extern const float lbl_805A2344;
extern float lbl_805A2360;
}

extern "C" void fn_800DB71C(float* self, void* arg1) {
    float vec[3];
    float out[3];

    fn_801ECD70(lbl_8049E030, arg1, vec);
    vec[2] = lbl_805A2360;
    fn_80162C48(out, lbl_8049E060, vec);

    self[0] = out[0] * lbl_805A02C0.a;
    self[1] = out[1] * lbl_805A02C0.b;
    self[2] = lbl_805A2344;
}
