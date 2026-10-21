#pragma force_active on
extern "C" void* fn_41_15FD4(void* p, int idx);
extern "C" bool fn_41_1AE7C(void* p);
extern "C" bool fn_41_1CAE4(void* p);

extern "C" bool fn_41_17B08(void* p, int idx) {
    if (idx == -1) {
        for (int i = 0; i < 8; i++) {
            void* q = fn_41_15FD4(p, i);
            if (!fn_41_1AE7C(q)) {
                if (!fn_41_1CAE4(q)) {
                    return false;
                }
            }
        }
    } else {
        return fn_41_1CAE4(fn_41_15FD4(p, idx));
    }
    return true;
}
