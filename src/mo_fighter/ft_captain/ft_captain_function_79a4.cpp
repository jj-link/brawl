#pragma force_active on
extern "C" void fn_27_711E4(void*, short, void*);
extern "C" void* fn_27_1AB96C(void*, unsigned char);

extern "C" void* fn_100_79A4(void* self, short id) {
    fn_27_711E4(self, id, (void*)((unsigned int)self + 0x24));
    fn_27_1AB96C((char*)self + 0x24, 0);
    return self;
}
