#pragma force_active on
extern void fn_8036C3A8(void* a, int b);
extern void fn_8035AF74(int a);
extern void fn_8035E00C(void* a);

void fn_80368BA0(void** arg0) {
    void* temp_r31;

    temp_r31 = *arg0;
    fn_8036C3A8(arg0, 1);
    fn_8035AF74(*(int*)((char*)temp_r31 + 0x444));
    fn_8035E00C(temp_r31);
    *arg0 = 0;
}
