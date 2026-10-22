#pragma force_active on

extern "C" int fn_80048F6C(int arg0) {
    int result;
    int flag;
    int shift;
    int idx;

    idx = 8;
    result = 0;
    flag = 0;

    if (arg0 > 1) {
        for (shift = 1; shift <= 2; shift++) {
            if (!((arg0 >> shift) & 1)) {
                idx = shift;
                flag = 1;
                break;
            }
        }

        if (flag != 0) {
            for (; idx < 11; idx++) {
                if (((arg0 >> idx) & 1) == 1) {
                    result = 1;
                    break;
                }
            }
        }
    }
    return result;
}
