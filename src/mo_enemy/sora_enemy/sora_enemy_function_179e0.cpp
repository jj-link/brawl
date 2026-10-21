#pragma force_active on
extern "C" void* fn_41_15FD4(void* p, int idx);
extern "C" bool fn_41_1AE7C(void* p);
extern "C" int fn_41_1CA10(void* p);

extern "C" int fn_41_179E0(void* p, int idx) {
    if (idx == -1) {
        for (int i = 0; i < 8; i++) {
            void* q = fn_41_15FD4(p, i);
            if (!fn_41_1AE7C(q)) {
                if (!fn_41_1CA10(q)) {
                    return 0;
                }
            }
        }
        goto done;
    } else {
        void* q = fn_41_15FD4(p, idx);
        return fn_41_1CA10(q);
    }
done:
    return 1;
}
