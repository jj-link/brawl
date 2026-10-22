#pragma force_active on

typedef struct Context {
    unsigned char pad0[0x10];
    int state;
    unsigned char pad14[0x28];
    int status;
    unsigned char pad40[0xC];
    int handle;
    unsigned char pad50[0xD0];
    int pending;
    unsigned char pad124[0x8];
    int field12C;
    unsigned char pad130[0x20];
    int busy;
} Context;

extern int CanReceiveOnSocket(int);
extern void fn_80380BA0(Context *);
extern void fn_80380C5C(Context *);
extern void fn_80380D60(Context *);
extern void fn_80380E00(Context *);
extern void fn_80381010(Context *);
extern void fn_80381148(Context *);
extern void fn_8038141C(Context *);
extern void fn_80381514(Context *);
extern void fn_803816E4(Context *);
extern void fn_80381BB8(Context *);
extern void fn_8038215C(Context *);
extern void fn_8037C81C(Context *);
extern void fn_8037E7F4(Context *);
extern void fn_8037BD4C(Context *);
extern void fn_8037C5AC(Context *);

int fn_8037E8B4(Context *self) {
    int pending;

    if (self->busy != 0) {
        return 0;
    }
    self->busy = 1;
    if (self->state == 0) {
        fn_80380BA0(self);
    }
    if (self->state == 1) {
        fn_80380C5C(self);
    }
    if (self->state == 2) {
        fn_80380D60(self);
    }
    if (self->state == 3) {
        fn_80380E00(self);
    }
    if (self->state == 4) {
        fn_80381010(self);
    }
    if (self->state == 5) {
        fn_80381148(self);
    }
    if (self->state == 6) {
        fn_8038141C(self);
    }
    if (self->state == 7) {
        fn_80381514(self);
    }
    if (self->state == 8) {
        fn_803816E4(self);
    }
    if (self->state == 9) {
        fn_80381BB8(self);
    }
    if (self->state == 10) {
        fn_8038215C(self);
    }
    if (self->field12C != 0) {
        fn_8037C81C(self);
    }
    pending = self->pending;
    if (self->status == 0x12 && pending == 0 &&
        CanReceiveOnSocket(self->handle) == 0) {
        self->pending = 1;
    }
    if (self->pending != 0) {
        fn_8037E7F4(self);
        fn_8037BD4C(self);
        fn_8037C5AC(self);
    } else {
        self->busy = 0;
    }
    return pending;
}
