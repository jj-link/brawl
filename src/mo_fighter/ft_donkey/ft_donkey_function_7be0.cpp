#pragma force_active on
extern "C" {
void fn_27_711E4(void*, short, void*);
void* fn_27_1AB96C(void*, unsigned char);

void* fn_92_7BE0(char* self, int v) {
    fn_27_711E4(self, (short)v, self + 0x24);
    fn_27_1AB96C(self + 0x24, 0);
    return self;
}
}
