#pragma force_active on
typedef void (*FuncPtr)(int, int, int);

struct Struct_801C4944 {
    unsigned char pad[0x1C];
    FuncPtr func;
    int value;
};

extern "C" void fn_801C4944(Struct_801C4944* self) {
    if (self->func == 0) {
        return;
    }
    self->func(0, 0, self->value);
}
