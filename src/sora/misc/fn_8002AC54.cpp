#pragma force_active on
extern float lbl_805A1528;

class gfPadStatus;

class gfPadSystem {
public:
    int getGamePadStatus(int arg0, gfPadStatus *arg1);
};

int gfPadSystem::getGamePadStatus(int arg0, gfPadStatus *arg1)
{
    char *self = (char *)this;
    char *out = (char *)arg1;

    if (arg0 == 0xF0) {
        *(int *)(out + 0x00) = *(int *)(self + 0x884);
        *(int *)(out + 0x04) = *(int *)(self + 0x888);
        *(int *)(out + 0x08) = *(int *)(self + 0x88C);
        *(int *)(out + 0x0C) = *(int *)(self + 0x890);
        *(int *)(out + 0x10) = *(int *)(self + 0x894);
        *(int *)(out + 0x14) = *(int *)(self + 0x898);
        *(float *)(out + 0x18) = *(float *)(self + 0x89C);
        *(float *)(out + 0x1C) = *(float *)(self + 0x8A0);
        *(float *)(out + 0x20) = *(float *)(self + 0x8A4);
        *(float *)(out + 0x24) = *(float *)(self + 0x8A8);
        *(float *)(out + 0x28) = *(float *)(self + 0x8AC);
        *(float *)(out + 0x2C) = *(float *)(self + 0x8B0);
        *(unsigned char *)(out + 0x30) = *(unsigned char *)(self + 0x8B4);
        *(unsigned char *)(out + 0x31) = *(unsigned char *)(self + 0x8B5);
        *(unsigned char *)(out + 0x32) = *(unsigned char *)(self + 0x8B6);
        *(unsigned char *)(out + 0x33) = *(unsigned char *)(self + 0x8B7);
        *(unsigned char *)(out + 0x34) = *(unsigned char *)(self + 0x8B8);
        *(unsigned char *)(out + 0x35) = *(unsigned char *)(self + 0x8B9);
        *(unsigned char *)(out + 0x36) = *(unsigned char *)(self + 0x8BA);
        *(unsigned char *)(out + 0x37) = *(unsigned char *)(self + 0x8BB);
        *(unsigned char *)(out + 0x38) = *(unsigned char *)(self + 0x8BC);
        *(int *)(out + 0x3C) = *(int *)(self + 0x8C0);
    } else if ((1 << arg0) & *(unsigned short *)(self + 0x3A)) {
        float f = lbl_805A1528;
        *(int *)(out + 0x14) = 0;
        *(int *)(out + 0x10) = 0;
        *(int *)(out + 0x0C) = 0;
        *(int *)(out + 0x08) = 0;
        *(int *)(out + 0x04) = 0;
        *(int *)(out + 0x00) = 0;
        *(unsigned char *)(out + 0x31) = 0;
        *(unsigned char *)(out + 0x30) = 0;
        *(unsigned char *)(out + 0x33) = 0;
        *(unsigned char *)(out + 0x32) = 0;
        *(unsigned char *)(out + 0x35) = 0;
        *(unsigned char *)(out + 0x34) = 0;
        *(unsigned char *)(out + 0x37) = 0;
        *(unsigned char *)(out + 0x36) = 0;
        *(float *)(out + 0x24) = f;
        *(float *)(out + 0x20) = f;
        *(float *)(out + 0x1C) = f;
        *(float *)(out + 0x18) = f;
        *(float *)(out + 0x2C) = f;
        *(float *)(out + 0x28) = f;
        *(int *)(out + 0x3C) = 0;
        *(unsigned char *)(out + 0x38) = 0;
    } else {
        char *src = self + (arg0 << 6);
        *(int *)(out + 0x00) = *(int *)(src + 0x444);
        *(int *)(out + 0x04) = *(int *)(src + 0x448);
        *(int *)(out + 0x08) = *(int *)(src + 0x44C);
        *(int *)(out + 0x0C) = *(int *)(src + 0x450);
        *(int *)(out + 0x10) = *(int *)(src + 0x454);
        *(int *)(out + 0x14) = *(int *)(src + 0x458);
        *(float *)(out + 0x18) = *(float *)(src + 0x45C);
        *(float *)(out + 0x1C) = *(float *)(src + 0x460);
        *(float *)(out + 0x20) = *(float *)(src + 0x464);
        *(float *)(out + 0x24) = *(float *)(src + 0x468);
        *(float *)(out + 0x28) = *(float *)(src + 0x46C);
        *(float *)(out + 0x2C) = *(float *)(src + 0x470);
        *(unsigned char *)(out + 0x30) = *(unsigned char *)(src + 0x474);
        *(unsigned char *)(out + 0x31) = *(unsigned char *)(src + 0x475);
        *(unsigned char *)(out + 0x32) = *(unsigned char *)(src + 0x476);
        *(unsigned char *)(out + 0x33) = *(unsigned char *)(src + 0x477);
        *(unsigned char *)(out + 0x34) = *(unsigned char *)(src + 0x478);
        *(unsigned char *)(out + 0x35) = *(unsigned char *)(src + 0x479);
        *(unsigned char *)(out + 0x36) = *(unsigned char *)(src + 0x47A);
        *(unsigned char *)(out + 0x37) = *(unsigned char *)(src + 0x47B);
        *(unsigned char *)(out + 0x38) = *(unsigned char *)(src + 0x47C);
        *(int *)(out + 0x3C) = *(int *)(src + 0x480);
    }
    return 1;
}
