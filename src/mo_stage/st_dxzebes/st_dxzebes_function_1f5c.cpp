#pragma force_active on
struct Consts { float f[100]; };
struct E { unsigned char flag; unsigned char pad[0x1F]; };
struct S {
    unsigned char pad0[0x220];
    E e[20];
    unsigned char pad4A0[0x4B8 - 0x4A0];
    short v4B8;
    unsigned char pad4BA[6];
    short v4C0;
    unsigned char pad4C2[0x71C - 0x4C2];
    float f71C, f720, f724, f728, f72C;
    unsigned char pad730[0x10];
    unsigned short v740;
};
extern "C" {
extern const Consts lbl_84_rodata_0;
float randf__Fv();
int randi__Fl(long);
void fn_84_14F8(void* object, unsigned int index, float x, float y, float scale, unsigned char state);
void playSeBasic__7stMeleeF5SndIDf(void*, int, float);
}

extern "C" void fn_84_1F5C(S* self) {
    const Consts* k = &lbl_84_rodata_0;
    if (self->v4B8 != 0) return;
    if (self->v740 != 0) {
        self->v740 = self->v740 - 1;
        return;
    }
    self->v4C0 = self->v4C0 - 1;
    if (self->v4C0 >= 0) return;

    int i;
    int idx = -1;
    int count = 0;
    for (i = 0; i < 20; i++) {
        if (self->e[i].flag != 0) {
            count++;
        } else if (idx == -1) {
            idx = i;
        }
    }
    if (count < 15) {
        float y = self->f72C;
        float z;
        float a = k->f[75] + self->f728;
        float b = (self->f71C - self->f728) - k->f[82];
        float c = self->f720 - y;
        z = k->f[40] + k->f[9] * randf__Fv();
        y = y + c * randf__Fv();
        fn_84_14F8(self, idx, a + b * randf__Fv(), y, z, 1);
        *(float*)((unsigned char*)self + idx * 0x20 + 0x234) = k->f[66];
        playSeBasic__7stMeleeF5SndIDf(self, 0x1DA9, k->f[10]);
    }
    self->v4C0 = randi__Fl(30) + 20;
}
