#pragma force_active on
extern "C" {
void* fn_120_B018(void*, int);
void* fn_120_AFF0(char*, int);
void* fn_120_AFD8(void*, int);
void* fn_120_AFC0(void*, int);
int fn_27_8D3E4(void*);
void fn_120_AE40(void* p) {
    char* obj = static_cast<char*>(p);
    int i;
    for (i = 0; i < 1; i++) {
        if (fn_27_8D3E4(static_cast<char*>(fn_120_B018(obj + 0x7e80, i)) + 0x88) == 0) return;
    }
    for (i = 0; i < 2; i++) {
        if (fn_27_8D3E4(static_cast<char*>(fn_120_AFF0(obj + 0x3e2c, i)) + 0x88) == 0) return;
    }
    for (i = 0; i < 1; i++) {
        if (fn_27_8D3E4(static_cast<char*>(fn_120_AFD8(obj + 0x2224, i)) + 0x88) == 0) return;
    }
    for (i = 0; i < 1; i++) {
        if (fn_27_8D3E4(static_cast<char*>(fn_120_AFC0(obj + 0xc, i)) + 0x88) == 0) return;
    }
}
}