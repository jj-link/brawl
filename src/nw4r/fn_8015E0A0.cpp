#pragma force_active on
extern "C" unsigned char fn_8015E0A0(void *a) {
    void *p1 = *(void **)((char *)a + 0x14);
    void *p2 = *(void **)((char *)p1 + 0x8);
    return *(unsigned char *)p2;
}
