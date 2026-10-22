#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_DB0;
extern const float lbl_27_rodata_DB4;
void fn_8009F1FC(void*);
}

struct Vec3 {
    float x, y, z;
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct State {
    char pad0[4];
    void* m4;
    float* m8;
    char padC[8];
    float data[5];
    Vec3 vec;
    float last;
    char pad38[4];
    unsigned char m3c;
};

extern "C" void fn_27_B1774(State* self) {
    fn_8009F1FC(self->m4);

    float* p = self->m8;
    self->data[0] = p[0];
    self->data[1] = p[1];
    self->data[2] = p[2];
    self->data[3] = p[3];
    self->data[4] = p[4];

    Vec3 v(lbl_27_rodata_DB0, lbl_27_rodata_DB0, lbl_27_rodata_DB0);
    self->vec = v;
    self->last = lbl_27_rodata_DB4;
    self->m3c = (self->m3c | 0xa0) & ~0x40;
}
