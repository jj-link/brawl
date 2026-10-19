#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_27_377094(void*);
extern "C" void fn_27_135160(void*, float, void*, void*);

extern "C" void fn_116_1FD1C(void* self, float f, void* a, void* b) {
    fn_27_377094(reinterpret_cast<u8*>(self) + 0x11130);
    fn_27_135160(self, f, a, b);
}
