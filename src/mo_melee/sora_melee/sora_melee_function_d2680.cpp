#pragma force_active on
extern "C" const float lbl_27_rodata_F04;

struct Vec3 {
    float x, y, z;

    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Data {
    Vec3 a, b, c, d;
    unsigned char flag0, flag1;
};

extern "C" void fn_27_D2680(Data* self) {
    Vec3 tmp[4];

    self->flag0 = 0;
    tmp[0].set(lbl_27_rodata_F04, lbl_27_rodata_F04, lbl_27_rodata_F04);
    self->a = tmp[0];
    tmp[1].set(lbl_27_rodata_F04, lbl_27_rodata_F04, lbl_27_rodata_F04);
    self->b = tmp[1];
    tmp[2].set(lbl_27_rodata_F04, lbl_27_rodata_F04, lbl_27_rodata_F04);
    self->c = tmp[2];
    tmp[3].set(lbl_27_rodata_F04, lbl_27_rodata_F04, lbl_27_rodata_F04);
    self->d = tmp[3];
    self->flag1 = 0;
}
