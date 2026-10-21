#pragma force_active on
int fn_8020A53C(int);

int fn_8020A4EC(int arg0) {
    if (arg0 == 0) {
        if (fn_8020A53C(0) == -1 || fn_8020A53C(1) == -1) {
            return 0;
        }
    }
    return 1;
}
