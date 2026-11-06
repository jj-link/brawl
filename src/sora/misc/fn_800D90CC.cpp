#pragma force_active on

extern "C" unsigned char fn_800C8548();

extern "C" void fn_800D90CC(void* arg0) {
    unsigned char idx = fn_800C8548();
    unsigned char* p;
    if (idx == 0xFF) {
        p = 0;
    } else {
        int addr = (int)arg0 + idx * 0x218;
        p = (unsigned char*)(addr + 0x70);
    }
    ((unsigned char*)arg0)[0xFEF] = p[0xE5];
    ((unsigned char*)arg0)[0xFF0] = p[0xEF];
    ((unsigned char*)arg0)[0xFF1] = p[0xF9];
    ((unsigned char*)arg0)[0xFF2] = p[0x103];
}
