#pragma force_active on
struct Obj {
    unsigned char pad[0x1A4];
    unsigned char flag;
};

extern "C" void fn_40_243D0(Obj*);
extern "C" void fn_27_264DDC(Obj*);

extern "C" void fn_40_3254C(Obj* self) {
    fn_40_243D0(self);
    if (self->flag) {
        self->flag = 0;
        fn_27_264DDC(self);
    }
}
