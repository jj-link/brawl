#pragma force_active on
extern "C" void fn_27_57F78(void* member);

extern "C" {
void fn_27_38441C(char* object) {
    char* p = object + 4;
    for (int i = 0; i < 2; i++) {
        fn_27_57F78(p);
        p += 8;
    }
}
}
