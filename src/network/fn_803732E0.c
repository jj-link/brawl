#pragma force_active on
extern char *strncpy(char *dst, const char *src, unsigned long n);

void fn_803732E0(void **arg0, const char *arg1) {
    char *temp_r31;

    temp_r31 = (char *)*arg0;
    strncpy(temp_r31, arg1, 0x100);
    temp_r31[0xFF] = 0;
}
