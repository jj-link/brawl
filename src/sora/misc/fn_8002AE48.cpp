#pragma force_active on
extern float lbl_805A1528;

class gfPadStatus;

class gfPadSystem {
public:
    int getSysPadStatus(int arg0, gfPadStatus *arg1);
};

int gfPadSystem::getSysPadStatus(int arg0, gfPadStatus *arg1)
{
    char *self = (char *)this;
    char *out = (char *)arg1;

    if (arg0 == 0xF0) {
        *(int *)(out + 0x00) = *(int *)(self + 0x844);
        *(int *)(out + 0x04) = *(int *)(self + 0x848);
        *(int *)(out + 0x08) = *(int *)(self + 0x84C);
        *(int *)(out + 0x0C) = *(int *)(self + 0x850);
        *(int *)(out + 0x10) = *(int *)(self + 0x854);
        *(int *)(out + 0x14) = *(int *)(self + 0x858);
        *(float *)(out + 0x18) = *(float *)(self + 0x85C);
        *(float *)(out + 0x1C) = *(float *)(self + 0x860);
        *(float *)(out + 0x20) = *(float *)(self + 0x864);
        *(float *)(out + 0x24) = *(float *)(self + 0x868);
        *(float *)(out + 0x28) = *(float *)(self + 0x86C);
        *(float *)(out + 0x2C) = *(float *)(self + 0x870);
        *(unsigned char *)(out + 0x30) = *(unsigned char *)(self + 0x874);
        *(unsigned char *)(out + 0x31) = *(unsigned char *)(self + 0x875);
        *(unsigned char *)(out + 0x32) = *(unsigned char *)(self + 0x876);
        *(unsigned char *)(out + 0x33) = *(unsigned char *)(self + 0x877);
        *(unsigned char *)(out + 0x34) = *(unsigned char *)(self + 0x878);
        *(unsigned char *)(out + 0x35) = *(unsigned char *)(self + 0x879);
        *(unsigned char *)(out + 0x36) = *(unsigned char *)(self + 0x87A);
        *(unsigned char *)(out + 0x37) = *(unsigned char *)(self + 0x87B);
        *(unsigned char *)(out + 0x38) = *(unsigned char *)(self + 0x87C);
        *(int *)(out + 0x3C) = *(int *)(self + 0x880);
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
        *(char *)(out + 0x38) = -1;
        *(int *)(out + 0x3C) = 0;
    } else {
        char *src = self + (arg0 << 6);
        *(int *)(out + 0x00) = *(int *)(src + 0x244);
        *(int *)(out + 0x04) = *(int *)(src + 0x248);
        *(int *)(out + 0x08) = *(int *)(src + 0x24C);
        *(int *)(out + 0x0C) = *(int *)(src + 0x250);
        *(int *)(out + 0x10) = *(int *)(src + 0x254);
        *(int *)(out + 0x14) = *(int *)(src + 0x258);
        *(float *)(out + 0x18) = *(float *)(src + 0x25C);
        *(float *)(out + 0x1C) = *(float *)(src + 0x260);
        *(float *)(out + 0x20) = *(float *)(src + 0x264);
        *(float *)(out + 0x24) = *(float *)(src + 0x268);
        *(float *)(out + 0x28) = *(float *)(src + 0x26C);
        *(float *)(out + 0x2C) = *(float *)(src + 0x270);
        *(unsigned char *)(out + 0x30) = *(unsigned char *)(src + 0x274);
        *(unsigned char *)(out + 0x31) = *(unsigned char *)(src + 0x275);
        *(unsigned char *)(out + 0x32) = *(unsigned char *)(src + 0x276);
        *(unsigned char *)(out + 0x33) = *(unsigned char *)(src + 0x277);
        *(unsigned char *)(out + 0x34) = *(unsigned char *)(src + 0x278);
        *(unsigned char *)(out + 0x35) = *(unsigned char *)(src + 0x279);
        *(unsigned char *)(out + 0x36) = *(unsigned char *)(src + 0x27A);
        *(unsigned char *)(out + 0x37) = *(unsigned char *)(src + 0x27B);
        *(unsigned char *)(out + 0x38) = *(unsigned char *)(src + 0x27C);
        *(int *)(out + 0x3C) = *(int *)(src + 0x280);
    }
    return 1;
}
