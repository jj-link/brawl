#pragma force_active on
extern "C" {
void fn_27_711E4(void*, short, void*);
void* fn_27_1AB96C(void*, unsigned char);
}

struct Ft94 {
    char pad[0x24];
    char sub[4];
};

extern "C" void* fn_94_7A3C(void* self, int arg) {
    Ft94* p = (Ft94*)self;
    fn_27_711E4(self, (short)arg, p->sub);
    fn_27_1AB96C(p->sub, 0);
    return self;
}
