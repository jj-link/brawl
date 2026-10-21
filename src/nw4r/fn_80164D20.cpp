#pragma force_active on
extern "C" {
    void fn_8015BF9C(void*, int);
    extern char lbl_804652C0[];
}

extern "C" void* fn_80164D20(void* obj) {
    char* p = (char*)obj;
    *(void**)(p + 0x1C) = lbl_804652C0;
    {
        void fn_8015BF9C(void*, int, void*);
        fn_8015BF9C(p + 0xC0, 0x14, lbl_804652C0);
    }
    fn_8015BF9C(p + 0xCC, 0x14);
    *(short*)(p + 0xD8) = 0;
    return obj;
}
