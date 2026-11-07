#pragma force_active on
extern void* fn_803D634C(void*, int, unsigned long);
int fn_803ECA2C(void* arg) {
    unsigned char* p = (unsigned char*)arg;
    fn_803D634C(p, 0, 0x200);
    if ((unsigned long)p & 3) {
        p[0] = 0x52; p[1] = 0x52; p[2] = 0x61; p[3] = 0x41;
    } else *(unsigned long*)p = 0x52526141;
    if ((unsigned long)(p + 0x1e4) & 3) {
        p[0x1e4] = 0x72; p[0x1e5] = 0x72; p[0x1e6] = 0x41; p[0x1e7] = 0x61;
    } else *(unsigned long*)(p + 0x1e4) = 0x72724161;
    if ((unsigned long)(p + 0x1e8) & 3) {
        p[0x1e8] = 0xff; p[0x1e9] = 0xff; p[0x1ea] = 0xff; p[0x1eb] = 0xff;
    } else *(unsigned long*)(p + 0x1e8) = 0xffffffff;
    if ((unsigned long)(p + 0x1ec) & 3) {
        p[0x1ec] = 0xff; p[0x1ed] = 0xff; p[0x1ee] = 0xff; p[0x1ef] = 0xff;
    } else *(unsigned long*)(p + 0x1ec) = 0xffffffff;
    if ((unsigned long)(p + 0x1fc) & 3) {
        p[0x1fc] = 0; p[0x1fd] = 0; p[0x1fe] = 0x55; p[0x1ff] = 0xaa;
    } else *(unsigned long*)(p + 0x1fc) = 0x55aa;
    return 0;
}