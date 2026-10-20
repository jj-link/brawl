#pragma force_active on
extern "C" void* fn_41_15FD4(void* p, int idx);
extern "C" bool fn_41_1AE7C(void* p);
extern "C" void fn_41_1CC18(void* p);

extern "C" void fn_41_17C30(void* p, int idx) {
    if (idx == -1) {
        for (int i = 0; i < 8; i++) {
            void* r = fn_41_15FD4(p, i);
            if (!fn_41_1AE7C(r)) {
                fn_41_1CC18(r);
            }
        }
    } else {
        fn_41_1CC18(fn_41_15FD4(p, idx));
    }
}
