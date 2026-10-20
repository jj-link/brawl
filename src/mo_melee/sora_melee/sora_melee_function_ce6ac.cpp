#pragma force_active on
struct Bits {
    unsigned int a : 9;
    unsigned int b : 9;
    unsigned int c : 14;
};

extern "C" void fn_27_CE6AC(void* self, unsigned int v) {
    ((struct Bits*)((char*)self + 8))->b = v;
}
