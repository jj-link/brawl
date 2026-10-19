#pragma force_active on
extern void* g_ftSlotManager;

extern "C" {
void fn_27_12006C(char* p, int a, int b, int c);
void fn_27_1456E4(void* unused, int idx, int code)
{
    if (code == 0x31) {
        fn_27_12006C(*(char**)g_ftSlotManager + idx * 0x4d4, 6, 0x15, 0);
    } else {
        fn_27_12006C(*(char**)g_ftSlotManager + idx * 0x4d4, 6, code, 0);
    }
}
}
