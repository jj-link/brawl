#pragma force_active on

typedef struct {
    char pad[0x1b40];
    int state;
    int unused;
    int error;
} State;

extern int *fn_803CD2A8(void);
extern int fn_803CD32C(void);
extern int fn_803CD3F4(void);
extern void fn_803CD410(int);
extern State *fn_803CD324(void);
extern int fn_803CF870(int, int, int, void *, int);
extern void fn_803D4950(void);

void fn_803D4AA8(void) {
    int *p;
    int r3;

    p = fn_803CD2A8();
    switch (fn_803CD32C()) {
    case 0:
        r3 = fn_803CF870(0, p[0], 0x1F1E0, (void *)fn_803D4950, 0);
        if ((r3 != 6) && ((r3 >= 6) || (r3 != 0))) {
            if (p[3] != 0) {
                ((void (*)(void))p[3])();
            }
        }
        break;
    case 2:
        switch (fn_803CD3F4()) {
        case -12:
            fn_803CD410(0);
            fn_803CD324()->state = 0;
            if (p[3] != 0) {
                ((void (*)(void))p[3])();
            }
            break;
        case -4:
            fn_803CD410(3);
            break;
        case -5:
        case -15:
            fn_803CD410(1);
            if (p[3] != 0) {
                ((void (*)(void))p[3])();
            }
            break;
        }
        break;
    }
}
