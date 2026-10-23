#pragma force_active on
int fn_8039B030(void *arg0, unsigned short arg1) {
    unsigned int v;
    v = *(unsigned int*)((char*)arg0 + 4);
    if (!(v & 0x100) || (v & 0x200)) {
        return -7;
    }
    if (!(v & 1)) {
        return -4;
    }
    *(unsigned int*)((char*)arg0 + 0x14) =
        (*(unsigned int*)((char*)arg0 + 0x14) & 0xFFFF0000u) | arg1;
    return 0;
}
