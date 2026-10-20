#pragma force_active on
struct Bits8 {
    unsigned int hi : 6;
    unsigned int lo : 26;
};

extern "C" void fn_27_AC2D0(void* p, unsigned int v) {
    Bits8* b = (Bits8*)((char*)p + 8);
    b->hi = v;
}
