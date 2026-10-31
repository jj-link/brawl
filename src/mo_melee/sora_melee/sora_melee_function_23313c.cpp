#pragma force_active on
typedef int s32;

extern "C" {
extern char* lbl_27_bss_5668;
void* fn_40_62A4(void* g, void* a, void* b, void* c, void* d);
}

extern "C" void* fn_27_23313C(void* a, void* b, void* c, void* d)
{
    char* g = lbl_27_bss_5668;
    if (g != 0 && *(s32*)(g + 0x44) == 0x3d) {
        return fn_40_62A4(g, a, b, c, d);
    }
    return g;
}
