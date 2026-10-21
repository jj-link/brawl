#pragma force_active on
extern int g_GameGlobal;

extern "C" {
void *memcpy(void *dst, const void *src, unsigned long n);

void *fn_80158D64(int arg0) {
    int dst = *(int *)(arg0 + 4);
    int src = *(int *)(g_GameGlobal + 0x30) + 0x650;
    return memcpy((void *)dst, (void *)src, 0x80);
}
}
