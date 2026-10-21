#pragma force_active on

struct lbl_805348E0_struct {
    int unk0;
    int initialized;
    int ready;
    int busy;
    unsigned char lock[0x18];
    unsigned char data[0xA0];
};

extern struct lbl_805348E0_struct lbl_805348E0;

extern void fn_8035D774(int);
extern unsigned int fn_8035D1B8(void *);
extern void fn_8035D248(void *);
extern void fn_8035D24C(void *);
extern void fn_8035D250(void *);
extern void fn_8035E380(void);
extern int fn_803FC9B8(void (*)(void));
extern void fn_8037EA50(void);
extern void *memset(void *, int, unsigned long);

void fn_8035E390(void)
{
    struct lbl_805348E0_struct *state = &lbl_805348E0;

    while (state->busy != 0) {
        fn_8035D774(100);
    }

    if (fn_8035D1B8(state) == 1U) {
        if (state->initialized == 0) {
            fn_8035D248(state->lock);
            fn_803FC9B8(fn_8035E380);
            state->initialized = 1;
        }
        fn_8035D24C(state->lock);
        fn_8035D250(state->lock);
        while (state->busy != 0) {
            fn_8035D774(100);
        }
        memset(state->data, 0, 0xA0);
        fn_8037EA50();
        state->ready = 1;
        return;
    }
    {
        while (state->initialized == 0) {
            fn_8035D774(100);
        }
        fn_8035D24C(state->lock);
        fn_8035D250(state->lock);
        while (state->ready == 0) {
            fn_8035D774(100);
        }
    }
}
