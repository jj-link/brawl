#pragma force_active on
extern "C" void fn_40_26B78(void* a, unsigned char b);

extern "C" void fn_40_F6C8(unsigned char* self) {
    fn_40_26B78(*(void**)(self + 0xc), self[0x10]);
}
