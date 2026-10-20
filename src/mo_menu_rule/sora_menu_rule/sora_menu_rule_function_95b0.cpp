#pragma force_active on
extern "C" {
void fn_18_CE0(void* p, int n);
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
void __dl__FPv(void* p);
void fn_800B8A0C(void* p, int n);
extern unsigned char lbl_18_data_18C8[];
}

extern "C" void* fn_18_95B0(const void* p, int n) {
    if (p) {
        *(void**)((char*)p + 0x668) = &lbl_18_data_18C8;
        void* q = *(void**)((char*)p + 0x66C);
        fn_800B8A0C(q, 1);
        if (p) {
            __destroy_arr((char*)p + 0x48, fn_18_CE0, 0xa8, 9);
        }
        if (n > 0) {
            __dl__FPv((void*)p);
        }
    }
    return (void*)p;
}
