#pragma force_active on
extern "C" {
void fn_802E56A8(void*, int);
void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;
}

extern "C" void* fn_802E1120(void* p, int n) {
    if (p) {
        fn_802E56A8(p, 0);
        if (n > 0) {
            fn_8027EABC(lbl_805A0EC8, p, *(unsigned short*)((char*)p + 4), 0x2c);
        }
    }
    return p;
}
