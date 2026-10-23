#pragma force_active on

extern "C" int fn_8004B848(void* arg0, unsigned int arg1) {
    unsigned int* entry;
    int found = 0;
    unsigned char i = 0;
    for (; i < 8; i++) {
        entry = (unsigned int*)((char*)arg0 + ((i * 4) & 0x3FC));
        if (entry[1] == arg1) {
            found = 1;
            entry[1] = 0;
            break;
        }
    }
    return found;
}
