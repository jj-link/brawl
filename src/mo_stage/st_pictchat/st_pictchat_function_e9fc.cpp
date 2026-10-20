#pragma force_active on
extern char lbl_73_data_5C18[];

extern "C" {
void __dl__FPv(void*);
void fn_73_2CC8(void*, int);

void* fn_73_E9FC(void* a, int b) {
    if (a) {
        void* p = *(void**)((char*)a + 0x168);
        *(void**)((char*)a + 0x3c) = lbl_73_data_5C18;
        if (p) {
            delete p;
        }
        *(void**)((char*)a + 0x168) = 0;
        fn_73_2CC8(a, 0);
        if (b > 0) {
            delete a;
        }
    }
    return a;
}
}
