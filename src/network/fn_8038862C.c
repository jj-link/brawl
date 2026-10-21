#pragma force_active on
void fn_8035AF74(void *p);
void fn_8035E00C(void *p);

void fn_8038862C(void **arg0) {
    char *temp_r31;

    temp_r31 = (char *)*arg0;
    fn_8035AF74(*(void **)(temp_r31 + 0x18));
    *(void **)(temp_r31 + 0x18) = 0;
    fn_8035E00C(temp_r31);
}
