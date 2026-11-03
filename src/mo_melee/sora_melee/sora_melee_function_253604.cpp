#pragma force_active on
extern "C" float randf__Fv();
extern float lbl_27_rodata_4100;

struct Obj {
    char pad0[0x1d4];
    int idx;
    char pad1[0x1e0 - 0x1d8];
    unsigned char active;
    char pad2[0x25c - 0x1e1];
    unsigned char* table;
    char pad3[4];
    int off;
    unsigned char arr[0x40];
    int a8;
    int ac;
    int b0;
    int b4;
};

extern "C" int fn_27_253604(Obj* self, unsigned char* out1, unsigned char* out2) {
    while (self->active != 0) {
        unsigned char* e = self->table + self->idx * 16;
        unsigned char op = e[0];
        if (op == 0xFE) {
            *out1 = e[2];
            *out2 = 0;
            if (*out1 == 0xFC) {
                unsigned char v;
                if (lbl_27_rodata_4100 < randf__Fv()) {
                    v = 0xFD;
                } else {
                    v = 0xFE;
                }
                *out1 = v;
            }
            unsigned char c = *out1;
            if (c == 0xFD) {
                *out1 = self->a8;
                *out2 = self->b0;
            } else if (c == 0xFE) {
                *out1 = self->ac;
                *out2 = self->b4;
            } else if (c == 0xFF) {
                *out1 = ((unsigned char*)self + self->off)[0x268];
            }
            return 1;
        }
        if (op == 0xFF) {
            self->active = 0;
        } else {
            self->idx = op;
        }
    }
    return 0;
}
