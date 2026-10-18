#pragma force_active on
extern char lbl_73_data_3A68[];

extern "C" {
void fn_73_2CC8(void*, int);

void* fn_73_35A0(char* a, int b) {
    if (a) {
        void* p = *(void**)(a + 0x284);
        *(void**)(a + 0x3c) = lbl_73_data_3A68;
        if (p) {
            delete p;
        }
        void* q = *(void**)(a + 0x174);
        *(void**)(a + 0x284) = 0;
        if (q) {
            delete[] q;
        }
        *(void**)(a + 0x174) = 0;
        fn_73_2CC8(a, 0);
        if (b > 0) {
            delete a;
        }
    }
    return a;
}
}
