#pragma force_active on
extern "C" void fn_27_57F78(void* member);

extern "C" void fn_105_DB18(char* self) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(self + 4 + index * 8);
    }
}
