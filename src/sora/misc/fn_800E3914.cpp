#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct Self {
    unsigned char pad0[0x14];
    int unk14;
    unsigned char pad18[0x18];
    void* objs[4];
    unsigned char pad40[0xbc];
    Vec3f pts[4];
    float t;
    int cnt0;
    int cnt1;
    unsigned char pad138[0x12c];
    float f264;
};

extern "C" void fn_800B6838(void*, const Vec3f*);
extern "C" double sin(double);
extern "C" const float lbl_805A2434;
extern "C" const float lbl_805A2438;
extern "C" const float lbl_805A243C;
extern "C" const float lbl_805A2440;

extern "C" int fn_800E3914(Self* self) {
    Vec3f p;
    int i;
    float t = self->t + lbl_805A2434;
    self->t = t;
    if (t >= lbl_805A2438) {
        int n;
        int m = 1 + self->cnt1;
        n = 1 + self->cnt0;
        self->cnt0 = n;
        self->cnt1 = m;
        if (n >= 4) {
            for (i = 0; i < 4; i++) {
                void* obj = self->objs[i];
                p.x = self->pts[i].x;
                p.y = self->pts[i].y;
                p.z = self->pts[i].z;
                fn_800B6838(obj, &p);
            }
            return 0;
        }
        self->t = t - lbl_805A2438;
    }
    float k = lbl_805A2440 * self->f264;
    float tt = self->t;
    float amp = lbl_805A243C + k;
    amp = amp * (float)sin((double)tt);
    for (i = 0; i < 4; i++) {
        void* obj = self->objs[i];
        p.x = self->pts[i].x;
        p.y = self->pts[i].y;
        p.z = self->pts[i].z;
        if ((i + self->cnt1) % 2 == 0) {
            p.x = p.x + amp;
        } else {
            p.y = p.y + amp;
        }
        fn_800B6838(obj, &p);
    }
    return self->unk14;
}
