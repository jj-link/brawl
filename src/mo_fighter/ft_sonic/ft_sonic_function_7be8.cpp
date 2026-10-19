#pragma force_active on
extern "C" void fn_27_711E4(void*, short, void*);
extern "C" void* fn_27_1AB96C(void*, unsigned char);

extern "C" {
void* fn_123_7BE8(void* self, int arg);
}

void* fn_123_7BE8(void* self, int arg) {
    fn_27_711E4(self, (short)arg, &((char*)self)[0x24]);
    fn_27_1AB96C((char*)self + 0x24, 0);
    return self;
}
