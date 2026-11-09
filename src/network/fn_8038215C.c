#pragma force_active on

typedef struct {
    char pad0[0x3C];
    int unk3C;
    char pad40[0x60];
    int unkA0;
    char padA4[4];
    int unkA8;
    int unkAC;
    char padB0[0x10];
    char unkC0;
    char padC1[0x5F];
    int unk120;
    int unk124;
    int unk128;
    char pad12C[0x58];
    int unk184;
    char pad188[0xC];
    int unk194;
} Fn8038215CStruct;

extern unsigned int fn_8035D728(void);
extern void *fn_8035DFE8(int);
extern void fn_8035E00C(void *);
extern int fn_8037BFCC(void *, void *, int *);
extern int fn_8037B644(void *, void *, int);
extern int fn_8037BE7C(void *);
extern int fn_8038194C(void *, void *, int);

void fn_8038215C(Fn8038215CStruct *self) {
    void *buf;
    int capacity;
    int outLen;
    unsigned int start;
    unsigned int elapsed;

    start = fn_8035D728();
    elapsed = 0;
    buf = fn_8035DFE8(0x2000);
    capacity = 0x2000;

    if (buf == 0) {
        self->unk120 = 1;
        self->unk3C = 1;
    } else {
        while (self->unk120 == 0 && elapsed < (unsigned int)self->unk184) {
            int result;

            outLen = capacity;
            result = fn_8037BFCC(self, buf, &outLen);

            if (result == 3 || result == 1) {
                break;
            }

            if (result == 2) {
                self->unk120 = 1;
                if (self->unk128 > 0 && self->unk124 < self->unk128) {
                    self->unk3C = 0xF;
                }
                break;
            }

            if (self->unk194 != 0) {
                if (fn_8037B644(&self->unkC0, buf, outLen) == 0) {
                    break;
                }
                self->unkA8 = self->unkAC;
                if (fn_8037BE7C(self) == 0) {
                    self->unk120 = 1;
                    self->unk3C = 0x11;
                    break;
                }
                if (self->unkA8 - self->unkAC != 0 &&
                    fn_8038194C(self,
                                (void *)(self->unkA0 + self->unkAC),
                                self->unkA8 - self->unkAC) == 0) {
                    break;
                }
                goto update_elapsed;
            } else if (fn_8038194C(self, buf, outLen) == 0) {
                break;
            }

        update_elapsed:
            elapsed = fn_8035D728() - start;
        }
        fn_8035E00C(buf);
        return;
    }
}
