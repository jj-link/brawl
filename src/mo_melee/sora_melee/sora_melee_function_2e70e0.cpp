#pragma force_active on
extern "C" {
void* fn_27_4E038(void*, short);
void* fn_27_37D3C(void*, short);
void* fn_27_4D8E0(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_2E70E0(void* arg0, int arg1) {
    if (arg0 != 0) {
        fn_27_4E038((char*)arg0 + 0xF0, -1);
        if ((unsigned long)((char*)arg0 + 0x6C) != 0) {
            __destroy_arr((char*)arg0 + 0x78, (void (*)(void*, int))fn_27_37D3C, 0x78, 1);
        }
        if (arg0 != 0) {
            __destroy_arr((char*)arg0 + 0xC, (void (*)(void*, int))fn_27_4D8E0, 0x60, 1);
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}