#pragma force_active on
extern "C" void fn_27_377094(void*);
extern "C" void fn_27_135160(void*, float, void*, void*);

extern "C" void fn_116_9EC8(void* self, float f, void* a, void* b) {
    fn_27_377094(reinterpret_cast<unsigned char*>(self) + 0x17fbc);
    fn_27_135160(self, f, a, b);
}
