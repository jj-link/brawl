#pragma force_active on
extern "C" int fn_801CDC14(void*, int, int, int);

struct Sub {
    unsigned char pad[0xbc];
    unsigned char flag;
};

struct Obj {
    unsigned char pad[0x10];
    Sub* sub;
    int f14;
    int f18;
    int f1c;
};

extern "C" void fn_801CF2DC(Obj* self) {
    if (fn_801CDC14(self->sub, self->f14, self->f18, self->f1c) == 0) {
        self->sub->flag = 1;
    }
}
