#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_70454(void*, int);

void* fn_27_291620(char* p, int n) {
    if (p) {
        __destroy_arr(p + 0xC, fn_27_70454, 4, 7);
        if (n > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
}
