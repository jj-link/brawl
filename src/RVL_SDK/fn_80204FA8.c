#pragma force_active on
unsigned int fn_80204FA8(unsigned int* arg0, unsigned char* arg1) {
    unsigned short off;
    unsigned char* ptr;

    if (arg1 == 0) {
        return arg0[0];
    }
    off = *(unsigned short*)((char*)arg0 + 10);
    ptr = arg1 + off;
    return *(unsigned int*)(ptr + 4);
}
