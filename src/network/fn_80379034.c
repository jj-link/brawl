#pragma force_active on
typedef struct Obj {
    int state;
    char pad4[0x98];
    void (*callback)(int, const char *, void *);
    char pada0[0xc];
    unsigned int ac;
    unsigned int b0;
    int b4;
    int b8;
    char padbc[0x50];
    void *context;
} Obj;
extern unsigned int fn_8035D728(void);
extern void fn_8037AC14(void *, int);
extern void fn_8037ABA0(void *);
extern char lbl_80490038[];

void fn_80379034(Obj *self) {
    unsigned int now = fn_8035D728();
    if (self->state != -1) {
        if (self->b8 > 0 && now - self->ac > 10000U) {
            if (self->b8 >= 4) {
                self->b8 = 0;
                self->callback(5, lbl_80490038, self->context);
                return;
            }
            fn_8037AC14(self, 3);
            self->b8++;
        } else if (self->b4 != 0 && now - self->ac > 10000U) {
            fn_8037AC14(self, 1);
        } else if (now - self->ac > 60000U || self->ac == 0 || now < self->ac) {
            fn_8037AC14(self, 0);
        }
        if (fn_8035D728() - self->b0 > 20000U) {
            fn_8037ABA0(self);
        }
    }
}