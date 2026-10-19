#pragma force_active on
struct fn_27_Obj {
    int unk0;
};

extern "C" fn_27_Obj* fn_27_2AC298(fn_27_Obj* p, int n) {
    if (p != 0 && n > 0) {
        delete p;
    }
    return p;
}
