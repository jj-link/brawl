#pragma force_active on

struct Entry {
    int unk0[5];
    int unk14;
    int unk18;
    int unk1C;
    void *unk20;
    int unk24;
    int unk28;
    void (*unk2C)(void *);
};

struct St {
    int unk0;
    int initialized;
    int ready;
    int busy;
    unsigned char lock[0x18];
    struct Entry *entries[0x28];
};

extern struct St lbl_805348E0;

extern int fn_8035D200(int *);
extern void fn_8035D24C(void *);
extern void fn_8035D250(void *);

void fn_8035E76C(void)
{
    char *w;
    struct Entry *e;
    struct St *state;
    void (*fp)(void *);
    int i;

    state = &lbl_805348E0;
    if (state->ready != 0) {
        fn_8035D24C(&lbl_805348E0.lock);
        if (fn_8035D200(&lbl_805348E0.unk0) != 0) {
            fn_8035D250(&lbl_805348E0.lock);
            return;
        }
        state->busy = 1;
        w = (char *)state;
        for (i = 0; i < 0x28; i++) {
            e = *(struct Entry **)(w + 0x28);
            if (e != 0) {
                fn_8035D24C(&lbl_805348E0.lock);
                if (e->unk14 != 0 && e->unk18 == 0) {
                    e->unk18 = 1;
                    fp = e->unk2C;
                    if (fp != 0) {
                        fp(e->unk20);
                    }
                }
                fn_8035D250(&lbl_805348E0.lock);
            }
            w += 4;
        }
        fn_8035D250(state->lock);
    }
}
