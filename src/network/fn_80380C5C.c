#pragma force_active on
typedef struct Context {
    unsigned char pad0[0x10];
    int state;
    unsigned char pad14[4];
    int fallback;
    unsigned int result;
    unsigned char pad20[0x1C];
    int status;
    unsigned char pad40[0xE0];
    int flag;
    unsigned char pad124[0x64];
    int handle;
    unsigned char pad18C[0x24];
    int pending;
} Context;

extern int lbl_805A1064;
extern unsigned int fn_8035C620(int);
extern int fn_8035D364(int, int *);
extern void fn_8037BDD4(Context *, int, int);

static inline int get_handle(Context *self) {
    if (self->handle != 0) {
        return self->handle;
    }
    if (lbl_805A1064 != 0) {
        return lbl_805A1064;
    }
    return self->fallback;
}

void fn_80380C5C(Context *self) {
    int handle;

    if (self->pending != 0) {
        self->state = 2;
        fn_8037BDD4(self, 0, 0);
        return;
    }

    handle = get_handle(self);
    self->result = fn_8035C620(handle);

    if (self->result == 0xFFFFFFFFU &&
        fn_8035D364(handle, &self->pending) == -1) {
        self->pending = 0;
        self->flag = 1;
        self->status = 4;
        return;
    }

    if (self->result == 0xFFFFFFFFU) {
        self->state = 2;
        fn_8037BDD4(self, 0, 0);
        return;
    }

    self->state = 3;
    fn_8037BDD4(self, 0, 0);
}
