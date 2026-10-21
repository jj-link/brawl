#pragma force_active on
extern "C" void fn_801D0180(void* p) {
    unsigned char* b = (unsigned char*)p;
    *(int*)(b + 0x318) = 0;
    b[0x31C] = 0;
    b[0x31D] = 0;
}
