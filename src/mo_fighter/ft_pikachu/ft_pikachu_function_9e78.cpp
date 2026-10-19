#pragma force_active on
extern "C" void fn_27_57ED8(void* member, void* argument);

extern "C" void fn_98_9E78(char* self, void* argument) {
    for (int i = 0; i < 2; i++) {
        char* p = self + i * 8;
        p = p + 4;
        fn_27_57ED8(p, argument);
    }
}
