#pragma force_active on
extern const float lbl_805A1A10;
extern const float lbl_805A1A14;

struct Data {
    int x, y, z, w;
    int ticks;
    int saved;
    unsigned char flag18;
    char pad19[3];
    unsigned char flag1C;
    unsigned char flag1D;
    char pad1E[0x32];
    int value50;
};

struct Obj {
    char pad000[0x1D0];
    Data* sub;
};

extern "C" void fn_8006A6A8(Obj* arg0, float a, float b, float c, float d) {
    Data* data = arg0->sub;
    if (lbl_805A1A10 == b) {
        b = a;
    }
    float k = lbl_805A1A14;
    data->x = (int)(k * a);
    data->y = (int)(k * b);
    data->z = (int)(k * c);
    data->w = (int)(k * d);
    data->ticks = (data->x * 60) / 2;
    data->flag1D = 0;
    data->saved = arg0->sub->value50;
    data->flag18 = 0;
    data->flag1C = 0;
}