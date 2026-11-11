#pragma force_active on
#pragma fp_contract on

extern "C" {
extern const float lbl_805A44F8;
extern void fn_80285A6C(void*, void*);
}

struct Mat { float m[16]; };

struct Obj {
    char pad[0xb0];
    Mat mat;                       // 0xb0
    char pad2[0x10];               // 0xf0
    float pos[4];                  // 0x100
    char pad3[0x20];               // 0x110
    float q[4];                    // 0x130
};

extern "C" void fn_802F2F58(Obj* self, void* arg1) {
    __attribute__((aligned(16))) float v[4];
    Mat* p = &self->mat;
    fn_80285A6C(p, arg1);

    float nx = self->q[0];
    float ny = self->q[1];
    float nz = self->q[2];

    v[0] = nx * p->m[0] + ny * p->m[4] + nz * p->m[8];
    v[1] = nx * p->m[1] + ny * p->m[5] + nz * p->m[9];
    v[2] = nx * p->m[2] + ny * p->m[6] + nz * p->m[10];
    v[3] = lbl_805A44F8;

    p->m[12] = self->pos[0] - v[0];
    p->m[13] = self->pos[1] - v[1];
    p->m[14] = self->pos[2] - v[2];
    p->m[15] = self->pos[3] - v[3];
}
