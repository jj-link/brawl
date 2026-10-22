#pragma force_active on

struct Obj {
    char pad[0xDC];
    int state;
    char padE0[0x218];
    int value;
    unsigned char flag;
};

struct Table {
    int pad[2];
    void (*fn)(Obj*);
};

extern "C" {
void fn_800B9804(void*, int);
void fn_8010535C(void*, int);
extern const Table lbl_804092A0;

void fn_801052DC(Obj* self, int arg1, int arg2) {
    fn_800B9804((char*)self + 0x34, (unsigned char)arg1);
    self->value = arg2;
    fn_8010535C(self, 1);
    self->flag = 0;
    self->state = 1;
    if (lbl_804092A0.fn != 0) {
        lbl_804092A0.fn(self);
    }
}
}
