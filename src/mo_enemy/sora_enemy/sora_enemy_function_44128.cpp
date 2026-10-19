#pragma force_active on
extern "C" int fn_41_44194(float f1);

extern "C" {
int fn_41_44128(float* p) {
    int ret = 0;
    if (fn_41_44194(p[0])) {
        if (fn_41_44194(p[1])) {
            if (fn_41_44194(p[2])) {
                ret = 1;
            }
        }
    }
    return ret;
}
}
