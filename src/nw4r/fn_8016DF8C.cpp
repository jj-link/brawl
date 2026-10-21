#pragma force_active on
extern "C" void fn_8016DF8C(unsigned char* self) {
    unsigned char* node = *(unsigned char**)(self + 0x38);
    while (node) {
        if (*(int*)(node + 0xc) == 1 && *(int*)(node + 0xd8) == 3) {
            *(int*)(node + 0xd8) = 1;
        }
        node = *(unsigned char**)(node + *(unsigned short*)(self + 0x42) + 4);
    }
}
