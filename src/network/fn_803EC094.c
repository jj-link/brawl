#pragma force_active on
extern int fn_803EB8B4(char);

int fn_803EC094(char arg0) {
    int result = fn_803EB8B4(arg0);
    if (result != 0 && result != 1) {
        result = -1;
    }
    return result;
}
