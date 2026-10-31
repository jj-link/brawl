#pragma force_active on
extern "C" {

void fn_800B9984(void*);

struct Self {
    char pad[0xDC];
    int state;
    char pad2[0x210];
    int value;
    unsigned char flag;
};

struct Entry {
    void (*fn0)(void*);
    int (*fn1)(void*);
};

extern const Entry lbl_804092A0[];

void fn_80105558(Self* self) {
    self->value = -1;
    self->flag = 0;
    fn_800B9984((char*)self + 0x34);

    int old = self->state;
    int (*fn1)(void*) = lbl_804092A0[old].fn1;
    if (fn1) {
        int ret = fn1(self);
        if (ret != old) {
            self->state = ret;
            void (*fn0)(void*) = lbl_804092A0[ret].fn0;
            if (fn0) {
                fn0(self);
            }
        }
    }
}

}
