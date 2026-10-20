#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void* fn_50_2034(void*, int);
extern unsigned char lbl_50_data_2990[];
}

extern "C" void* fn_50_9F4C(void* p, int flag) {
    if (p) {
        void* arr = *(void**)((char*)p + 0x198);
        *(void**)((char*)p + 0x3c) = &lbl_50_data_2990;
        if (arr) {
            __dl__FPv(arr);
        }
        *(void**)((char*)p + 0x198) = 0;
        fn_50_2034(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
