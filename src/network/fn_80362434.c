#pragma force_active on
extern void fn_8037EF20(int);

typedef struct Obj {
    unsigned char pad[0x28];
    int f28;
    int f2c;
    int f30;
} Obj;

void fn_80362434(Obj* self) {
    if (self->f30 == 0) {
        if (self->f28 >= 0) {
            fn_8037EF20(self->f28);
        }
        self->f2c = 0x12;
        self->f30 = 1;
    }
}
