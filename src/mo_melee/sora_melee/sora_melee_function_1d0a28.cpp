#pragma force_active on
struct Work {
    int m0;
    int m4;
    int m8;
};

extern "C" {
int fn_27_1D0A28(Work *work) {
    return work->m8 >> 29;
}
}
