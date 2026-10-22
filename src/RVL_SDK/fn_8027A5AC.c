#pragma force_active on
typedef unsigned char u8;

extern int fn_8021A024(int, void *);
extern int fn_8021A118(int, void *);
extern int fn_8021A180(int, void *);
extern void fn_8027A1D4(void);
extern void fn_8027A2E8(void);

void fn_8027A5AC(void *self) {
    int sp8;
    int r;

    *(int *)((u8 *)self + 0x28) = fn_8021A118(*(int *)self, (void *)fn_8027A1D4);
    *((u8 *)self + 0x44) = 1;
    r = fn_8021A024(*(int *)self, &sp8);
    switch (r) {
    case 0:
        *(int *)((u8 *)self + 0x2C) = fn_8021A180(*(int *)self, (void *)fn_8027A2E8);
        *((u8 *)self + 0x40) = 1;
        break;
    case -1:
        *((u8 *)self + 0x40) = 0;
        break;
    }
}
