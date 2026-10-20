#pragma force_active on
struct fn_27_1A44D8_bits {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 12;
};

extern "C" void fn_27_1A44D8(void* self, unsigned int v) {
    ((fn_27_1A44D8_bits*)((char*)self + 8))->b = v;
}
