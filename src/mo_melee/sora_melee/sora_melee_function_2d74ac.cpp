#pragma force_active on

struct Constants {
    float zero;
    float pad[8];
    float limit;
    float negative;
};

extern "C" {
extern const Constants lbl_27_rodata_6300[];

int fn_27_2D74AC(float* arg0, float* arg1, float farg0, float farg1, float farg2) {
    const Constants* constants = lbl_27_rodata_6300;
    int result = 0;

    farg1 *= farg0 - *arg0;
    float limit = constants->limit;
    if (__fabs(farg1) < limit) {
        if (farg1 >= constants->zero)
            farg1 = limit;
        else
            farg1 = constants->negative;
    }

    float old = *arg1;
    float next = old + farg2 * (farg1 - old);
    *arg1 = next;

    float pos = *arg0 + next;
    *arg0 = pos;

    if (*arg1 > constants->zero) {
        if (pos >= farg0)
            result = 1;
    } else if (*arg1 < constants->zero) {
        if (pos <= farg0)
            result = 1;
    }

    if (result) {
        *arg0 = farg0;
        *arg1 = constants->zero;
    }

    return result;
}
}
