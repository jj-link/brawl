#pragma force_active on
extern "C" void* fn_41_15FD4(char* p, int idx);
extern "C" bool fn_41_1AE7C(void* p);
extern "C" void fn_41_1BF64(void* p, void* q);

extern "C" void fn_41_16360(char* self, int idx) {
    if (idx == -1) {
        for (int i = 0; i < 8; i++) {
            void* p = fn_41_15FD4(self, i);
            if (fn_41_1AE7C(p) == 0) {
                fn_41_1BF64(p, *(void**)(self + 0x20));
            }
        }
    } else {
        fn_41_1BF64(fn_41_15FD4(self, idx), *(void**)(self + 0x20));
    }
}
