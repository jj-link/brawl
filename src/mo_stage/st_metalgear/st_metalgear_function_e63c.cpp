#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void* fn_71_276C(void* p, int flag);
}

extern "C" char lbl_71_data_37D0[];

extern "C" void* fn_71_E63C(void* p, int flag) {
    if (p != 0) {
        void* member = *(void**)((char*)p + 0x178);
        *(void**)((char*)p + 0x3c) = &lbl_71_data_37D0;
        if (member != 0) {
            __dl__FPv(member);
        }
        *(void**)((char*)p + 0x178) = 0;
        fn_71_276C(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
