#pragma force_active on
typedef float f32;

extern "C" void* fn_41_15FD4(char* p, int idx);
extern "C" bool fn_41_1AE7C(void* p);
extern "C" void fn_41_1F058(void* self, f32 value);

extern "C" void fn_41_17840(char* self, int idx, f32 value) {
    if (idx == -1) {
        for (int i = 0; i < 8; i++) {
            void* p = fn_41_15FD4(self, i);
            if (!fn_41_1AE7C(p)) {
                fn_41_1F058(p, value);
            }
        }
    } else {
        void* p = fn_41_15FD4(self, idx);
        fn_41_1F058(p, value);
    }
}
