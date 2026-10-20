#pragma force_active on
extern "C" void* fn_41_15FD4(char* p, int idx);
extern "C" bool fn_41_1AE7C(void* p);
extern "C" void fn_41_1E248(void* a, void* b);

extern "C" void fn_41_17DA8(void* a, int b) {
    if (b == -1) {
        for (int i = 0; i < 8; i++) {
            void* ptr = fn_41_15FD4((char*)a, i);
            if (!fn_41_1AE7C(ptr)) {
                fn_41_1E248(ptr, *(void**)((char*)a + 0x20));
            }
        }
    } else {
        void* ptr = fn_41_15FD4((char*)a, b);
        fn_41_1E248(ptr, *(void**)((char*)a + 0x20));
    }
}
