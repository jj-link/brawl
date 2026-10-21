#pragma force_active on
int fn_803D6D64(void* arg0) {
    unsigned short val = *(unsigned short*)((char*)arg0 + 0x1F8C);
    return (val >> 2) & 1;
}
