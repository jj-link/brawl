#pragma force_active on
typedef struct { char pad[0x1b40]; int state; } State;
typedef struct { char pad[12]; void (*callback)(void); } Context;
extern int fn_803CD270(void);
extern int fn_803CE570(void);
extern Context *fn_803CD2A8(void);
extern void fn_803D4AA8(void);
extern int fn_803CEEFC(int, int, void *);
extern int fn_803CD3F4(void);
extern void fn_803D6150(void);
extern State *fn_803CD324(void);
extern int fn_803CD32C(void);
int fn_803D4BD8(void (*callback)(void)) {
    Context *p;
    if (fn_803CD270() == 0) return 5;
    if (fn_803CE570() != 0) return 5;
    p = fn_803CD2A8();
    if (p == 0) return 5;
    p->callback = callback;
    switch (fn_803CEEFC(0, 1, (void *)fn_803D4AA8)) {
    case 0:
    case 6:
        break;
    case 2:
        if (fn_803CD3F4() == -12) {
            fn_803D6150();
            fn_803CD324()->state = 0;
            if (p->callback != 0) p->callback();
        }
        break;
    }
    return fn_803CD32C();
}