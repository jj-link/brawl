#pragma force_active on
extern "C" int fn_8005C198(void *arg0) {
    void *p = *(void **)((char *)arg0 + 0xC);
    if (p == 0) {
        return 0;
    }
    return *(unsigned short *)((char *)p + 0x18) + *(unsigned short *)((char *)p + 0xC);
}
