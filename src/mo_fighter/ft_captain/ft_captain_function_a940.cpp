#pragma force_active on
extern "C" {
char* fn_100_AA5C(void*, int);
char* fn_100_AA74(void*, int);
int fn_27_8D3E4(void*);
}

extern "C" void fn_100_A940(void* object) {
    for (int i = 0; i < 1; ++i) {
        char* weapon = fn_100_AA74((char*)object + 0x1F40, i);
        if (fn_27_8D3E4(weapon + 0x88) == 0)
            return;
    }
    for (int i = 0; i < 1; ++i) {
        char* weapon = fn_100_AA5C((char*)object + 0xC, i);
        if (fn_27_8D3E4(weapon + 0x88) == 0)
            return;
    }
}
