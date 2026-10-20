#pragma force_active on
extern "C" void fn_1_7E90(unsigned char* self, unsigned int a, unsigned int b) {
    unsigned char* mid = *(unsigned char**)(self + 0x104);
    unsigned char* inner = *(unsigned char**)mid;
    *(unsigned int*)(inner + 0x40) = a;
    *(unsigned int*)(inner + 0x44) = b;
}
