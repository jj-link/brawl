#pragma force_active on
struct Bits {
    unsigned int unused0 : 6;
    unsigned int field : 6;
    unsigned int unused1 : 20;
};

extern "C" void fn_40_1E42C(void* self, unsigned int value) {
    ((Bits*)((char*)self + 8))->field = value;
}
