#pragma force_active on

struct Entry {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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

extern void fn_8035D24C(void *);
extern void fn_8035D250(void *);
extern unsigned int fn_8035D728(void);
extern void fn_8035E494(struct Entry *);
extern void fn_8037EAA0(void);

void fn_8035E69C(unsigned int arg0)
{
    struct St *state = &lbl_805348E0;
    int i;
    int all = 1;
    unsigned int start;

    if (state->ready != 0) {
        fn_8035D24C(state->lock);
        start = fn_8035D728();
        for (i = 0; i < 0x28; i++) {
            struct Entry *e = state->entries[i];
            if (e != 0) {
                all = 0;
                if (e->unkC == 1) {
                    fn_8035E494(e);
                }
            }
            if (arg0 != 0 && (unsigned int)(fn_8035D728() - start) > arg0) {
                break;
            }
        }
        if (state->busy != 0 && all != 0) {
            fn_8037EAA0();
            state->busy = 0;
        }
        fn_8035D250(state->lock);
    }
}
