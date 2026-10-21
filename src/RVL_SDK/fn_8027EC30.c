#pragma force_active on
void fn_8027EC30(void* arg0, unsigned int arg1, unsigned int arg2) {
    unsigned int mask = arg1 & 0xF;
    *(unsigned int*)((char*)arg0 + 0x18) = 0xFFFFFFFF;
    *(unsigned int*)((char*)arg0 + 0x20) = arg2;
    if (mask != 0) {
        unsigned int aligned = (arg1 + 0x10) - mask;
        *(unsigned int*)((char*)arg0 + 0x10) = aligned;
        *(unsigned int*)((char*)arg0 + 0x1C) = aligned + (arg2 - mask);
    } else {
        *(unsigned int*)((char*)arg0 + 0x10) = arg1;
        *(unsigned int*)((char*)arg0 + 0x1C) = arg1 + arg2;
    }
}
