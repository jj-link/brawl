#pragma force_active on
typedef struct State {
    char pad0[0x5ec];
    char queue[0x254];
    int connected;
    char pad844[0x5c];
    void (*callback)(int, int);
    char pad8a4[0x14];
    unsigned int kind;
    char pad8bc[5];
    unsigned char error;
    char pad8c2[0x72];
    char data[0x59];
    unsigned char busy;
    unsigned char value;
} State;
extern State *lbl_804F6810[];
extern unsigned char lbl_805A0C88[4];
extern char lbl_8047C9B8[];
extern void fn_8021E41C(void *);
extern int fn_8021DC5C(void *, unsigned int, unsigned char, void (*)(int, int));
extern int fn_8021DE7C(void *, int, unsigned int, void (*)(int, int));
extern int fn_8021E1E8(void *, void *, unsigned short, unsigned int, void (*)(int, int));
extern void fn_8022550C(void *, ...);
void fn_8021E47C(int index, int result) {
    State *state = lbl_804F6810[index];
    int error;
    if (result != 0) {
        fn_8021E41C(state->queue);
        state->busy = 0;
        if (result == -1) {
            error = 0xfd;
        } else if (state->connected != 0) {
            if (lbl_805A0C88[index]++ < 0x20) {
                state = lbl_804F6810[index];
                fn_8021E41C(state->queue);
                fn_8021DC5C(state->queue, state->kind, state->value, fn_8021E47C);
                state->busy = 1;
                fn_8021DE7C(state->queue, 0x55, 0x04a400f0, fn_8021E47C);
                fn_8021DE7C(state->queue, 0, 0x04a400fb, fn_8021E47C);
                fn_8021E1E8(state->queue, state->data, 6, 0x04a400fa, fn_8021E47C);
                return;
            }
            error = 0xfc;
        } else {
            fn_8022550C(lbl_8047C9B8);
            fn_8021DC5C(state->queue, state->kind, state->value, 0);
            return;
        }
        state->error = error;
        if (state->callback != 0) {
            state->callback(index, error);
        }
    }
}