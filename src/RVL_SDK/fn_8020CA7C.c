#pragma force_active on
extern int strncmp(const char *s1, const char *s2, unsigned long n);
extern char lbl_8047C17C[];

int fn_8020CA7C(const char *arg0) {
    if (strncmp(arg0, lbl_8047C17C, 9) == 0 && arg0[9] != 0) {
        return 1;
    }
    return 0;
}
