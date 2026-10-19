#pragma force_active on
extern "C" void fn_27_26399C(void*);

extern "C" void fn_76_2664(unsigned char* self, void* unused, unsigned char* arg) {
    fn_27_26399C(*reinterpret_cast<void**>(self + 0x14c));
    unsigned char* base = *reinterpret_cast<unsigned char**>(self + 0x160);
    if (base != 0) {
        base[arg[0x35]] = 1;
    }
}
