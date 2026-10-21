#pragma force_active on
extern "C" {

int fn_801C6C04(int, int*);

int fn_801C8E68(int arg1, int arg2) {
    int sp[5];
    int val;
    val = 0;
    if (fn_801C6C04(arg2, sp) != 0) {
        val = sp[4];
    }
    return val * 0xA000;
}

}
