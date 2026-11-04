#pragma force_active on
extern "C" unsigned char fn_800C8548();

extern "C" unsigned char fn_800D6958(void* arg0) {
    unsigned char idx = fn_800C8548();
    unsigned char* p;
    if (idx == 0xFF) {
        p = 0;
    } else {
        int addr = (int)arg0 + idx * 0x218;
        p = (unsigned char*)(addr + 0x70);
    }
    if (p == 0 || (*(int*)((char*)arg0 + 0xFCC) >> 24) < 3) {
        return 0xFF;
    }
    return p[3];
}