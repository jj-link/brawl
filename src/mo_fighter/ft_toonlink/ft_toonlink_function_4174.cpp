#pragma force_active on
extern "C" void fn_27_711E4(void*, short, void*);
extern "C" void* fn_27_1AB96C(void*, unsigned char);

extern "C" {
void* fn_121_4174(void* self, int arg) {
    char* p = (char*)self;
    fn_27_711E4(self, (short)arg, p + 0x24);
    fn_27_1AB96C(p + 0x24, 0);
    return self;
}
}
