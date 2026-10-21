#pragma force_active on

typedef unsigned int u32;
typedef long long s64;

extern "C" {
int fn_80355EFC();
int fn_8035638C();
int fn_80356424(int*, int*);
void OSSleepTicks(s64);
}

struct Context {
    unsigned char pad[0x340];
    int state;
    int value1;
    int value2;
    unsigned char flag34C;
    unsigned char pad34D;
    unsigned char flag34E;
};

extern "C" int fn_80151904(Context* self) {
    int a;
    int b;

    do {
        switch (fn_80355EFC()) {
        case 0:
        case 4:
            return 0;
        case 1:
        case 3:
            return 1;
        case 2:
            if (self->state == 3) {
                if (self->flag34C) {
                    if (fn_8035638C() == 0)
                        return 0;
                } else {
                    if (fn_80356424(&a, &b)) {
                        self->value1 = a;
                        self->value2 = b;
                    }
                }
            }
            break;
        }

        OSSleepTicks(15 * (s64)((*(u32*)0x800000F8 / 4) / 1000));
    } while (self->flag34E);

    return 0;
}
