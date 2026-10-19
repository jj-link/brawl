#pragma force_active on
extern "C" {
void* fn_41_66BDC(void*, int);
int fn_27_8D3E4(void*);
}

extern "C" void fn_41_66B70(void* p) {
    int i = 0;
    while (i < 20) {
        if (fn_27_8D3E4(fn_41_66BDC(static_cast<char*>(p) + 0xc, i)) == 0) {
            break;
        }
        i++;
    }
}
