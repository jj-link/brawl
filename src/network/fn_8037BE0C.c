#pragma force_active on
typedef struct {
    char pad0[4];
    int field4;
    char pad8[0x40];
    int field48;
    char pad4c[0x118];
    int *field164;
    int field168;
    int field16c;
    int field170;
    void (*callback)(int, int, int, int, int, int);
} Object;

extern int fn_8035A590(int *);

void fn_8037BE0C(Object *self) {
    if (self->callback != 0) {
        self->callback(self->field4, self->field16c, self->field170,
                       self->field168, fn_8035A590(self->field164), self->field48);
    }
}
