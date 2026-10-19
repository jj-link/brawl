#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_27_377094(void*);
extern "C" void fn_27_135160(void*, float, void*, void*);

extern "C" void fn_116_184F8(void* self, float f, void* a, void* b) {
    fn_27_377094(reinterpret_cast<u8*>(self) + 0x1630c);
    fn_27_135160(self, f, a, b);
}
