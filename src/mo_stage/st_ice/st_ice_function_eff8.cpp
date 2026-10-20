#pragma force_active on
extern "C" void fn_62_EFF8(void* a, unsigned int b) {
    typedef struct {
        unsigned int before : 2;
        unsigned int field : 2;
        unsigned int after : 28;
    } Bits;
    Bits* p = (Bits*)((unsigned char*)a + 8);
    p->field = b & 0x3;
}
