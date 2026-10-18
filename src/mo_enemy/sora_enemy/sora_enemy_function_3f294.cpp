#pragma force_active on
extern "C" void* fn_41_3F304(void* self, int index);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_3F294(void* self) {
    for (int i = 0; i < 2; ++i) {
        if (fn_27_8D3E4(static_cast<char*>(fn_41_3F304(
                static_cast<char*>(self) + 0x0C, i)) + 0x94) == 0) {
            return;
        }
    }
}
