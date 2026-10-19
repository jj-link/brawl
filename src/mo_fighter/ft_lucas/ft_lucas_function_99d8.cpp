#pragma force_active on
extern "C" {
void fn_27_711E4(void*, short, void*);
void* fn_27_1AB96C(void*, unsigned char);

struct Fn114Obj {
    unsigned char pad[0x24];
    unsigned char sub[4];
};

void* fn_114_99D8(void* self, unsigned short arg) {
    Fn114Obj* o = (Fn114Obj*)self;
    fn_27_711E4(self, (short)arg, o->sub);
    fn_27_1AB96C(o->sub, 0);
    return self;
}
}
