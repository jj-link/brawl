#pragma force_active on
extern "C" {
void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;

void* fn_802E1E88(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_8027EABC(lbl_805A0EC8, arg0, *(unsigned short*)((char*)arg0 + 4), 0x2C);
    }
    return arg0;
}
}
