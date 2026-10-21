#pragma force_active on
extern "C" void* fn_41_15FD4(void* p, int idx);
extern "C" bool fn_41_1AE7C(void* p);
extern "C" int fn_41_1CA50(void* p);

extern "C" int fn_41_17A74(void* p, int idx) {
    if (idx == -1) {
        for (int i = 0; i < 8; i++) {
            void* q = fn_41_15FD4(p, i);
            if (fn_41_1AE7C(q)) continue;
            if (fn_41_1CA50(q) != 0) continue;
            return 0;
        }
    } else {
        void* q = fn_41_15FD4(p, idx);
        return fn_41_1CA50(q);
    }
    return 1;
}
