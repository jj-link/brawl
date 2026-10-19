#pragma force_active on
extern "C" {
struct Obj {
    unsigned char pad[0x3C];
    void* ptr;
    unsigned char gap[0x10];
    unsigned int value;
};

void fn_27_2418F4(Obj*);
extern unsigned char lbl_27_data_4DD20[];

Obj* fn_27_2416C0(Obj* self) {
    fn_27_2418F4(self);
    self->value = 0x18;
    self->ptr = lbl_27_data_4DD20;
    return self;
}
}
