#pragma force_active on
struct PeachArrayHolder {
    int unused[3];
    int* values;
};

extern "C" void fn_103_A254(PeachArrayHolder* holder, int divisor, int index) {
    if (divisor == 0) {
        return;
    }

    holder->values[index] /= divisor;
}
