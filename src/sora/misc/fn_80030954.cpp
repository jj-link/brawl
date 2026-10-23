#pragma force_active on

struct Flags {
    unsigned char a : 1;
    unsigned char b : 1;
    unsigned char c : 1;
    unsigned char d : 2;
    unsigned char e : 3;
};

struct Object {
    char pad0[0xA0];
    int a0;
    int a4;
    char padA8[0x48];
    int f0;
    int f4;
    Flags f8;
    unsigned char f9;
    char padFA[2];
    unsigned short fc;
    char padFE[2];
    int x100;
    int x104;
    int x108;
};

extern "C" int fn_80030954(Object* self, int arg1, int arg2) {
    if (self->f0 != 0) {
        return 0;
    }

    self->f0 = 1;
    self->f4 = 0;
    self->f9 = 0;
    self->x100 = 0;
    self->x108 = arg1;
    self->f8.a = 0;
    self->f8.d = 0;
    self->f8.b = arg2 == 8;
    self->f8.c = arg2 == 7;

    bool var_r9 = arg2 == 8 || arg2 == 7;
    if (var_r9 != 0) {
        arg2 = 0;
    }

    self->x104 = arg2;
    self->fc = 0;
    self->a0 = 0;
    self->a4 = 0;

    if (arg2 == 0) {
        self->f4 = 4;
    }
    return 1;
}
