#pragma force_active on
extern "C" unsigned char getLanguage__10GameGlobalFv(unsigned char *self) {
    void *p = *(void **)(self + 0x24);
    return *(unsigned char *)((unsigned char *)p + 0x82a);
}
