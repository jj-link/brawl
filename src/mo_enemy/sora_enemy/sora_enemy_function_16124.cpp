#pragma force_active on
extern "C" void* fn_41_15FD4(void* p, int idx);
extern "C" bool fn_41_1AE7C(void* p);
extern "C" void fn_41_1EF58(void* self, float value);

extern "C" void fn_41_16124(void* self, int idx, float f) {
    if (idx == -1) {
        for (int i = 0; i < 8; i++) {
            void* p = fn_41_15FD4(self, i);
            if (fn_41_1AE7C(p) == 0) {
                fn_41_1EF58(p, f);
            }
        }
    } else {
        void* p = fn_41_15FD4(self, idx);
        fn_41_1EF58(p, f);
    }
}
