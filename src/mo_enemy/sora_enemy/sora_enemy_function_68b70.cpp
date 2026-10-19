#pragma force_active on
typedef int s32;

extern "C" void* fn_41_68BDC(void*, s32);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_68B70(char* p) {
    s32 i = 0;
    while (i < 6) {
        if (fn_27_8D3E4(fn_41_68BDC(p + 0xc, i)) == 0) {
            break;
        }
        i++;
    }
}
