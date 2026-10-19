#pragma force_active on
extern "C" int fn_27_8D3E4(void*);
extern "C" void* fn_41_3B948(void*, int);

extern "C" void fn_41_3B8DC(char* p) {
    int i = 0;
    while (i < 6) {
        if (fn_27_8D3E4(fn_41_3B948(p + 0xc, i)) == 0) {
            break;
        }
        i++;
    }
}
