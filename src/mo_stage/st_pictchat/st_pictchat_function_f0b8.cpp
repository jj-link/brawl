#pragma force_active on
extern char lbl_73_data_5C18[];

extern "C" {
void __dl__FPv(void*);
void fn_73_2CC8(void*, int);

void* fn_73_F0B8(void* a, int b) {
    void* ret = a;
    if (a != 0) {
        if (a != 0) {
            void* p168 = *(void**)((char*)a + 0x168);
            *(void**)((char*)a + 0x3c) = (void*)lbl_73_data_5C18;
            if (p168 != 0)
                __dl__FPv(p168);
            *(void**)((char*)a + 0x168) = 0;
            fn_73_2CC8(a, 0);
        }
        if (b > 0)
            __dl__FPv(a);
    }
    return ret;
}
}
