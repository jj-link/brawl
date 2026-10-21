#pragma force_active on
int fn_80335238(void);
void fn_8037EEDC(void);

int fn_80335A80(void) {
    if (fn_80335238() != 0) {
        return 0;
    }
    fn_8037EEDC();
    return 1;
}
