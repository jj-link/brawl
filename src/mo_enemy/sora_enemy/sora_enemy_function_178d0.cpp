#pragma force_active on
extern "C" void* fn_41_15FD4(char* p, int idx);
extern "C" bool fn_41_1AE7C(void* p);
extern "C" void fn_41_1F060(void* p);

extern "C" void fn_41_178D0(char* self, int idx) {
    if (idx == -1) {
        for (int i = 0; i < 8; i++) {
            void* p = fn_41_15FD4(self, i);
            if (!fn_41_1AE7C(p)) {
                fn_41_1F060(p);
            }
        }
    } else {
        fn_41_1F060(fn_41_15FD4(self, idx));
    }
}
