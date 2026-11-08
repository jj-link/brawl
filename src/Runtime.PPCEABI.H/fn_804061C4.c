#pragma force_active on
void fn_804061C4(int unused, int arg1) {
    int t;
    int i = 0;
    if (arg1 > 0) {
        t = arg1 - 8;
        if (arg1 > 8) {
            for (; i < t; i += 8) ;
        }
        for (; i < arg1; i++) ;
    }
}
