#pragma force_active on
extern "C" void* fn_41_15FD4(char* p, int idx);
extern "C" bool fn_41_1AE7C(void* p);
extern "C" void fn_41_1C038(void* p, void* q);

extern "C" void fn_41_163E4(void* p, int idx) {
    if (idx == -1) {
        for (int i = 0; i < 8; i++) {
            void* ptr = fn_41_15FD4((char*)p, i);
            if (!fn_41_1AE7C(ptr)) {
                fn_41_1C038(ptr, *(void**)((char*)p + 0x20));
            }
        }
    } else {
        void* ptr = fn_41_15FD4((char*)p, idx);
        fn_41_1C038(ptr, *(void**)((char*)p + 0x20));
    }
}
