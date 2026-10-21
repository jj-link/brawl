#pragma force_active on
extern "C" void* fn_41_15FD4(void* p, int idx);
extern "C" bool fn_41_1AE7C(void* p);
extern "C" void fn_41_1EF60(void* p, float f);

extern "C" void fn_41_16094(void* p, int idx, float f) {
    if (idx == -1) {
        for (int i = 0; i < 8; i++) {
            void* q = fn_41_15FD4(p, i);
            if (!fn_41_1AE7C(q)) {
                fn_41_1EF60(q, f);
            }
        }
    } else {
        void* q = fn_41_15FD4(p, idx);
        fn_41_1EF60(q, f);
    }
}
