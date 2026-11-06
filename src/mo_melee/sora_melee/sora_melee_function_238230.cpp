#pragma force_active on
extern "C" {
extern char lbl_27_data_4C970[];
void __dla__FPv(void*);
void __dl__FPv(void*);
void* fn_27_238230(void* object, int flag) {
    if (object) {
        char* a = (char*)object;
        void* p = *(void**)(a + 0x14);
        *(void**)a = lbl_27_data_4C970;
        if (p) __dla__FPv(p);
        p = *(void**)(a + 0x18);
        *(void**)(a + 0x14) = 0;
        *(void**)(a + 4) = 0;
        if (p) {
            if (p) __dla__FPv((char*)p - 0x10);
        }
        p = *(void**)(a + 0x1c);
        *(void**)(a + 0x18) = 0;
        *(void**)(a + 8) = 0;
        if (p) {
            if (p) __dla__FPv((char*)p - 0x10);
        }
        p = *(void**)(a + 0x20);
        *(void**)(a + 0x1c) = 0;
        *(void**)(a + 0xc) = 0;
        if (p) __dla__FPv(p);
        *(void**)(a + 0x20) = 0;
        *(void**)(a + 0x10) = 0;
        if (flag > 0) __dl__FPv(object);
    }
    return object;
}
}