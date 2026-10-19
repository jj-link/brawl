#pragma force_active on
extern "C" void fn_27_238984(void* a, void* b);
extern float lbl_27_data_547E0;

struct Sub {
    char p0[4];
    float f4;
};

struct Obj {
    char pad0[0x10];
    Sub* sub10;
    char pad14[0xC];
    void* ptr20;
    char pad24[4];
    float f28;
    unsigned char state2c;
    char pad2d[3];
    char pad30[4];
};

extern "C" {
void fn_40_10160(Obj* self) {
    if (self->state2c == 1) {
        fn_27_238984(self->pad30, self->ptr20);
        float a = self->f28;
        float b = lbl_27_data_547E0;
        self->f28 = a + b;
        if (self->f28 >= self->sub10->f4) {
            self->state2c = 0;
        }
    }
}
}
