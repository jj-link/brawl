#pragma force_active on
typedef void (*FnPtr)(int, int);

extern char lbl_804E4580[0x100];
extern char lbl_80476B34[];
extern char lbl_804E44AC[0xD4];
extern FnPtr lbl_805A09A0;

int fn_801FE75C(void);
int fn_8020B06C(void *, int, int, void *, void *);
void fn_801FC09C(void);

void fn_801FC130(unsigned int arg0) {
    if (arg0 == 1) {
        *(int *)(lbl_804E4580 + 0x10) = fn_801FE75C();
    } else {
        *(int *)(lbl_804E4580 + 0x10) = -1;
    }
    if (fn_8020B06C(lbl_80476B34, 0x3F, 0, (void *)fn_801FC09C, lbl_804E44AC) != 0) {
        if (lbl_805A09A0 != 0) {
            lbl_805A09A0(2, 0);
        }
    }
}
