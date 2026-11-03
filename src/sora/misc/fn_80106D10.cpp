#pragma force_active on
extern "C" {
void __dl__FPv(void*);

struct Obj {
    char pad0[0x14];
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    char pad38[0x8];
    int m40;
    char pad44[0x14];
    int m58;
    int m5C;
    char pad60[0x18];
    void* m78;
};

void fn_80106D10(Obj* self) {
    if (self->m14 != 0) {
        self->m14 = 0;
    }
    if (self->m18 != 0) {
        self->m18 = 0;
    }
    if (self->m34 != 0) {
        self->m34 = 0;
    }
    if (self->m1C != 0) {
        self->m1C = 0;
    }
    if (self->m20 != 0) {
        self->m20 = 0;
    }
    if (self->m24 != 0) {
        self->m24 = 0;
    }
    if (self->m28 != 0) {
        self->m28 = 0;
    }
    if (self->m40 != 0) {
        self->m40 = 0;
    }
    if (self->m2C != 0) {
        self->m2C = 0;
    }
    if (self->m30 != 0) {
        self->m30 = 0;
    }
    if (self->m58 != 0) {
        self->m58 = 0;
    }
    if (self->m5C != 0) {
        self->m5C = 0;
    }
    void* temp = self->m78;
    if (temp != 0) {
        __dl__FPv(temp);
        self->m78 = 0;
    }
}
}
