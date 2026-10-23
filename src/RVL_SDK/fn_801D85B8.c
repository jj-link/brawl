#pragma force_active on

typedef int s32;

extern int fn_801D6410(int, void *);
extern void DBPrintf(const char *, ...);
extern void fn_801D8534(void);
extern char lbl_804676D8[];

void fn_801D85B8(void) {
    fn_801D6410(7, fn_801D8534);
    *(s32 *)0x800000D8 = 0;
    DBPrintf(lbl_804676D8);
}
