#pragma force_active on
extern "C" {
void fn_27_711E4(void*, short, void*);
void* fn_27_1AB96C(void*, unsigned char);
}

struct Pad24 { unsigned char pad[0x24]; };

extern "C" void* fn_98_8190(Pad24* self, int event) {
    fn_27_711E4(self, static_cast<short>(event), self + 1);
    fn_27_1AB96C(self + 1, 0);
    return self;
}
