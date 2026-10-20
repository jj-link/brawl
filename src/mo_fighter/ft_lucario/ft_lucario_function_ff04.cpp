#pragma force_active on
extern "C" void fn_118_FF90(void* self, int index, float a, float b);

extern "C" void fn_118_FF04(void* self, float a, float b) {
    unsigned char* base = static_cast<unsigned char*>(self);
    unsigned char* sub = *reinterpret_cast<unsigned char**>(base + 0xD8);
    void* target = *reinterpret_cast<void**>(sub + 0x7C);
    fn_118_FF90(target, 3, a, b);
    fn_118_FF90(target, 2, a, b);
    fn_118_FF90(target, 0, a, b);
    fn_118_FF90(target, 1, a, b);
}
