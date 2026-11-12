#pragma force_active on
#pragma optimization_level 1
extern unsigned char *lbl_805A0F88;

int fn_80342270(unsigned char **arg0);
int fn_80342244(unsigned char **arg0);

int fn_8033A798(unsigned char **arg0) {
    unsigned char *p = lbl_805A0F88;
    if (p == 0) {
        return 0;
    }
    *arg0 = p + 0x648;
    p = lbl_805A0F88;
    if (p[0x375] == 2 || p[0x375] == 3) {
        return fn_80342270(arg0);
    }
    return fn_80342244(arg0);
}
