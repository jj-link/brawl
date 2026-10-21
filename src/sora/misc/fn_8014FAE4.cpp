#pragma force_active on
extern void *g_GameGlobal;

extern "C" {
void fn_8014FAE4(unsigned long arg0) {
    char *p = *(char **)((char *)g_GameGlobal + 0x34);
    p[0x7F] = (unsigned char)(arg0 >> 24);
    p[0x80] = (unsigned char)(arg0 >> 16);
    p[0x81] = (unsigned char)(arg0 >> 8);
    p[0x82] = (unsigned char)arg0;
}
}
