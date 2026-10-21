#pragma force_active on
extern "C" {
extern void fn_803EF2AC(void* a, void* b);

void fn_8007B070(void* arg0, short* arg1) {
    short* p = arg1;
    char* q = (char*)arg0;
    while (1) {
        *(short*)(q + 0x5A) = *p;
        if (*p == 0xD3) {
            break;
        }
        p++;
        q += 2;
    }
    fn_803EF2AC(*(void**)((char*)arg0 + 0x54), (char*)arg0 + 0x5A);
}
}
