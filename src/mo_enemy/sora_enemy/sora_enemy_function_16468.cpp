#pragma force_active on
extern "C" void* fn_41_15FD4(void*, int);
extern "C" bool fn_41_1AE7C(void*);
extern "C" void fn_41_1C110(void*, void*);

extern "C" void fn_41_16468(void* p, int idx) {
    if (idx == -1) {
        for (int i = 0; i < 8; i++) {
            void* result = fn_41_15FD4(p, i);
            if (!fn_41_1AE7C(result)) {
                fn_41_1C110(result, *(void**)((char*)p + 0x20));
            }
        }
    } else {
        void* result = fn_41_15FD4(p, idx);
        fn_41_1C110(result, *(void**)((char*)p + 0x20));
    }
}
