#pragma force_active on
void OSRegisterVersion(const char *version);
int fn_803900FC(void *a, int b, int c, int d);
void *fn_803974FC(void);
extern int lbl_8059FCB8;
extern int lbl_805A1148;

int NHTTPStartup(int arg0, int arg1, int arg2) {
    void *temp_r31;
    int r;

    temp_r31 = fn_803974FC();
    if (lbl_805A1148 == 0) {
        OSRegisterVersion((const char *)lbl_8059FCB8);
        lbl_805A1148 = 1;
    }
    r = fn_803900FC(temp_r31, arg0, arg1, arg2);
    return -!r;
}
