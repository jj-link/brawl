#pragma force_active on
extern "C" void fn_80112E50(void* arg0, unsigned int arg1) {
    unsigned char* base = (unsigned char*)arg0 + 0x68;
    for (int i = 0; i < 8; i++) {
        if (*(unsigned int*)base == arg1) {
            *(unsigned int*)base = 0;
            *(unsigned int*)(base + 4) = 0xFFFF;
            *(unsigned char*)(base + 8) = 0;
            return;
        }
        base += 0xC;
    }
}
