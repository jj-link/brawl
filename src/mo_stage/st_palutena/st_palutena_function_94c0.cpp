#pragma force_active on
extern "C" void fn_67_CA24(void*, int, int, int);

struct Obj {
    unsigned char pad[0xD4];
    int* field;
};

extern "C" void fn_67_94C0(Obj* self, int arg) {
    fn_67_CA24(self, arg, 0, 0);
    self->field[1] = 0x11;
}
