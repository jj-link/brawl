#pragma force_active on

extern "C" void* fn_41_15FD4(void* p, int idx);
extern "C" bool fn_41_1AE7C(void* p);
extern "C" bool fn_41_1CB78(void* p);

extern "C" bool fn_41_17B9C(void* p, int idx) {
    if (idx == -1) {
        for (int i = 0; i < 8; i++) {
            void* q = fn_41_15FD4(p, i);
            if (fn_41_1AE7C(q) == 0) {
                if (fn_41_1CB78(q) == 0) {
                    return false;
                }
            }
        }
    } else {
        return fn_41_1CB78(fn_41_15FD4(p, idx));
    }
    return true;
}
