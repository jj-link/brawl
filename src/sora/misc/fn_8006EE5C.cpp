#pragma force_active on

extern "C" void* fn_8006CBA0(int arg0);
extern "C" const float lbl_805A1A74;
extern "C" const float lbl_805A1A78;

extern "C" void fn_8006EE5C(void* arg0, int arg1) {
    void* ret = fn_8006CBA0(arg1);
    ((int*)arg0)[0x48 / 4] = (int)ret;
    if (arg1 != 4) {
        if (arg1 < 4) {
            if (arg1 < 0) {
                return;
            }
            goto set_one;
        } else {
            if (arg1 >= 9) {
                goto done;
            }
            goto set_one;
        }
    } else {
        ((float*)arg0)[0x68 / 4] = lbl_805A1A78;
        return;
    }
set_one:
    ((float*)arg0)[0x68 / 4] = lbl_805A1A74;
done:
    return;
}
