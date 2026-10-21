#pragma force_active on
struct FnStruct {
    char pad[0x4C];
    int f4C;
    int f50;
    int f54;
};

extern "C" void fn_800606C4(FnStruct* arg0, int arg1) {
    if (arg1 != 0) {
        int val;
        if (arg0->f50) {
            val = arg0->f50;
        } else {
            val = arg0->f4C;
        }
        arg0->f54 = val;
    } else {
        arg0->f54 = arg0->f4C;
    }
}
