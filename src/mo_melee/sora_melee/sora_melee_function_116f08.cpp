#pragma force_active on
extern "C" void* fn_27_13231C(void* p);

extern "C" void* fn_27_116F08(unsigned char* p) {
    if (p[0xf] != 6) {
        return p;
    }
    unsigned char idx = p[0xa];
    void* sub = *(void**)(p + (idx << 3) + 0x34);
    return fn_27_13231C(sub);
}
