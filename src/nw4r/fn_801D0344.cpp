#pragma force_active on
extern "C" {
void fn_801CFA14();
void fn_801D00C0();
void fn_801CFE70();

int fn_801D0344(void* arg0) {
    while (*(unsigned char*)((char*)arg0 + 0x31C) == 0) {
        fn_801CFA14();
        fn_801D00C0();
        if (*(unsigned char*)((char*)arg0 + 0x31C) != 0)
            break;
        fn_801CFA14();
        fn_801CFE70();
    }
    return 0;
}
}
