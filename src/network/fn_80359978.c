#pragma force_active on
typedef struct { const char *name; int type; int value; } Item;
typedef struct { const char *name; Item *items; int count; } Request;
extern char lbl_80415790[];
extern int lbl_8048E680[];
extern Item lbl_80534618;
extern Request lbl_80534628;
extern void fn_80335638(int, const char *, ...);
extern void fn_80359FF8(int, int);
extern int fn_8038D4C8(int);
extern int fn_8038D4D0(int, Request *, void (*)(int, int, int), int);
extern void fn_80359A94(int, int, int);
void fn_80359978(void) {
    fn_80335638(4, lbl_80415790 + 0x45c);
    lbl_80534618.name = lbl_80415790 + 0x477;
    lbl_80534618.type = 2;
    lbl_80534618.value = lbl_8048E680[10];
    lbl_80534628.items = &lbl_80534618;
    lbl_80534628.count = 1;
    switch (lbl_8048E680[7]) {
    case 0:
        lbl_80534628.name = lbl_80415790 + 0x47c;
        break;
    case 1:
    case 2:
    case 3:
        lbl_80534628.name = lbl_80415790 + 0x485;
        break;
    case 4:
        lbl_80534628.name = lbl_80415790 + 0x48c;
        break;
    }
    if (fn_8038D4D0(lbl_8048E680[2], &lbl_80534628, fn_80359A94, 0) == 0) {
        fn_80359FF8(2, fn_8038D4C8(lbl_8048E680[2]));
        lbl_8048E680[0] = 5;
        lbl_8048E680[1] = 3;
    } else {
        lbl_8048E680[0] = 4;
    }
}