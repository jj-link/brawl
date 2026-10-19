#pragma force_active on
extern "C" void fn_27_711E4(void*, short, void*);
extern "C" void* fn_27_1AB96C(void*, unsigned char);

struct Obj {
    char pad[0x24];
    char sub[1];
};

extern "C" {
void* fn_120_69F4(Obj* self, int id) {
    fn_27_711E4(self, (short)id, self->sub);
    fn_27_1AB96C(self->sub, 0);
    return self;
}
}
