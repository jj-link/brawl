#pragma force_active on
struct fn_27_Bits {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int field : 10;
    unsigned int rest : 22;
};

extern "C" void fn_27_1A3374(void* obj, unsigned int value) {
    ((fn_27_Bits*)obj)->field = value;
}
