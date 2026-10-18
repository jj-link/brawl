#pragma force_active on
extern "C" {
int fn_800B5854(int, int, int, int, int);

int fn_10_F76C(int self) {
    return fn_800B5854(*(int*)(self + 0x414), 3, 1, 1, 0);
}
}
