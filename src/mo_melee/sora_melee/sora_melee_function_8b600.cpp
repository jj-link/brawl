#pragma force_active on
struct ValueAccesser {
    int kind;
};

extern "C" {
extern ValueAccesser* lbl_27_bss_1B00[5];
}

extern "C" ValueAccesser* fn_27_8B600(ValueAccesser* p, int free) {
    if (p) {
        lbl_27_bss_1B00[p->kind] = 0;
        if (free > 0) {
            delete p;
        }
    }
    return p;
}
