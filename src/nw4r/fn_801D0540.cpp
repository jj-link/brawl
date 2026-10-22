#pragma force_active on
extern "C" {
int fn_801B891C(void*);
}

struct Obj {
    unsigned char _00[0x0c];
    void* _0c;
    unsigned char _10[0xa4 - 0x10];
    void (*_a4)(Obj*, int, int);
    int _a8;
    unsigned char _ac;
    unsigned char _ad;
    unsigned char _ae;
};

extern "C" void fn_801D0540(Obj* self) {
    if (self->_ac != 0 && self->_ae != 0) {
        int ok = 0;
        if (self->_0c != 0 && fn_801B891C(self->_0c) != 0) {
            ok = 1;
        }
        if (ok != 0) {
            if (self->_a4 != 0) {
                self->_a4(self, 0, self->_a8);
            }
            self->_ae = 0;
            self->_ad = 0;
        }
    }
}
