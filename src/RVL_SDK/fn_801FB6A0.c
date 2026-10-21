#pragma force_active on
extern int fn_801FEBB8(unsigned int);
extern char lbl_804E4360[];

int fn_801FB6A0(unsigned int obj) {
    if (obj == (unsigned int)&lbl_804E4360) {
        return 1;
    }
    return fn_801FEBB8(obj);
}
