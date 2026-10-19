#pragma force_active on
extern "C" void exit__6gfTaskFv(void*);

struct Task {
    char pad[0x104];
    int f104;
};

struct Self {
    char pad0[0x48];
    int f48;
    char pad1[0x4F0 - 0x4C];
    int f4F0;
    char pad2[0x504 - 0x4F4];
    int f504;
    char pad3[0x540 - 0x508];
    Task* f540;
};

extern "C" int fn_15_4DA0(Self* self) {
    Task* t = self->f540;
    if (t->f104 == 3) {
        exit__6gfTaskFv(t);
        self->f540 = 0;
        if (self->f4F0 != 0) {
            self->f48 = 3;
        } else {
            self->f48 = 4;
        }
        return 11;
    }
    return self->f504;
}
