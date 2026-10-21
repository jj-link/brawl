#pragma force_active on
extern "C" void fn_80195ED0(void** arg0) {
    char* base = (char*)(*arg0);
    *(unsigned short*)(base + 0x18) = 0xFFFF;
    char* p = base;
    for (unsigned int i = 0; i < (unsigned int)(unsigned char)base[0x1A]; i++) {
        *(unsigned short*)(p + 0x3C) = 0xFFFF;
        p += 2;
    }
}
