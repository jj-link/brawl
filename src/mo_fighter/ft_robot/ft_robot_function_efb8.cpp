#pragma force_active on
extern "C" {
void fn_120_E5CC(void* arg);
void fn_120_E6D4(void* arg, int value);
void fn_120_EA24(void* arg);

void fn_120_EFB8(void* a1, void* a2) {
    fn_120_E5CC(a2);
    fn_120_E6D4(a2, 1);
    fn_120_EA24(a2);
}
}
