#pragma force_active on
extern "C" {
    extern int fn_802F8EC0(int arg);

    void fn_802EA818(void* a0, void* a1) {
        void** p = (void**)((char*)a1 + 0x14);
        void** q = (void**)((char*)*p + 8);
        fn_802F8EC0((int)*q);
    }
}
