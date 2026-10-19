#pragma force_active on
struct Obj {
    char pad[0x24];
    char field;
};

extern "C" void fn_27_711E4(void*, short, void*);
extern "C" void* fn_27_1AB96C(void*, unsigned char);

extern "C" void* fn_105_8E7C(Obj* self, short event) {
    fn_27_711E4(self, event, (char*)self + 0x24);
    fn_27_1AB96C(&self->field, 0);
    return self;
}
