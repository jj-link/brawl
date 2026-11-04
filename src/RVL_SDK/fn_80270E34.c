#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef void (*Callback)(int, int);

typedef struct {
    u8 pad0[0x14];
    Callback callback;
} Callbacks;

typedef struct {
    u8 pad0[4];
    Callbacks *callbacks;
    u8 pad8[0x8E - 8];
    u8 flag;
    u8 pad8F[0x5E8 - 0x8F];
    u16 value5E8;
    u16 value5EA;
    u16 value5EC;
    u8 pad5EE[2];
    int value5F0;
    int value5F4;
    u8 state[0x740 - 0x5F8];
    float value740;
    float value744;
    float value748;
    float value74C;
    float value750;
    float value754;
    int value758;
    int value75C;
} Object;

extern u16 fn_802009D0(void);
extern u16 fn_802009D8(void);
extern u16 fn_802009E0(void);
extern void fn_80203CF8(int *, int *);
extern void fn_801FFF54(int *, int *);
extern int fn_8026F4D4(int);
extern void fn_8026F4E0(int);
extern void fn_80203CEC(int (*)(int), void (*)(int));
extern void fn_80202620(void *);
extern void fn_8020270C(void);
extern void fn_801FFE28(void (*)(void), void *);
extern void fn_80200A00(u16);
extern void fn_80200A08(u16);
extern void fn_80200A10(u16);
extern const float lbl_805A3AF4;
extern const float lbl_805A3AF8;
extern const float lbl_805A3B30;
extern const float lbl_805A3B34;

void fn_80270E34(Object *self) {
    Callback callback = self->callbacks->callback;
    if (callback) {
        callback(0, 0);
    }
    self->value5E8 = fn_802009D0();
    self->value5EA = fn_802009D8();
    self->value5EC = fn_802009E0();
    fn_80203CF8(&self->value5F0, &self->value5F4);
    fn_801FFF54(&self->value758, &self->value75C);
    fn_80203CEC(fn_8026F4D4, fn_8026F4E0);
    self->value750 = lbl_805A3AF4;
    self->value748 = lbl_805A3B30;
    self->value740 = lbl_805A3B34;
    self->value74C = lbl_805A3AF4;
    self->value754 = lbl_805A3AF4;
    self->value744 = lbl_805A3AF8;
    fn_80202620(self->state);
    fn_801FFE28(fn_8020270C, self->state);
    fn_80200A00(0x8000);
    fn_80200A08(0);
    fn_80200A10(0);
    callback = self->callbacks->callback;
    if (callback) {
        callback(1, 0);
    }
    self->flag = 1;
}
