#pragma force_active on
typedef struct {
    void *m00;
    char pad04[0x18];
    void *m1c;
    char pad20[0x350];
    void *m370;
    char pad374[0x18];
    unsigned char m38c;
    char pad38d[0xcb];
    void *m458;
} Obj;
extern Obj *lbl_805A0F88;
extern char lbl_80489E70[];
extern void fn_80335638(int, const char *, ...);
extern void fn_80335450(int, void *, int);
extern void fn_803791BC(void *);
extern void fn_803895D0(void *);
extern void fn_8033C0D4(void);
extern void fn_80383470(void);
extern int fn_80367CB0(void **, int, int, int);
extern void fn_80367C74(void **);
extern void fn_80367C54(void **);
extern void fn_803389BC(void);
extern void fn_80337468(void);
extern void fn_803424AC(void);
extern void fn_8034EB74(void);
extern void fn_80374880(void *);
void DWC_ShutdownFriendsMatch(void) {
    fn_80335638(4, lbl_80489E70, lbl_805A0F88);
    if (lbl_805A0F88 != 0) {
        if (lbl_805A0F88->m370 != 0) {
            fn_803791BC(lbl_805A0F88->m370);
            lbl_805A0F88->m370 = 0;
        }
        lbl_805A0F88->m38c = 0;
        if (lbl_805A0F88->m458 != 0) {
            fn_803895D0(lbl_805A0F88->m458);
            lbl_805A0F88->m458 = 0;
        }
        fn_8033C0D4();
        fn_80383470();
        if (lbl_805A0F88->m1c != 0) {
            fn_80367CB0(&lbl_805A0F88->m1c, 0, 0, 0);
            fn_80367CB0(&lbl_805A0F88->m1c, 3, 0, 0);
            fn_80367CB0(&lbl_805A0F88->m1c, 1, 0, 0);
            fn_80367CB0(&lbl_805A0F88->m1c, 2, 0, 0);
            fn_80367C74(&lbl_805A0F88->m1c);
            fn_80367C54(&lbl_805A0F88->m1c);
            lbl_805A0F88->m1c = 0;
        }
        fn_803389BC();
        fn_80337468();
        fn_803424AC();
        fn_8034EB74();
        if (lbl_805A0F88->m00 != 0) {
            fn_80374880(lbl_805A0F88->m00);
            lbl_805A0F88->m00 = 0;
        }
        fn_80335450(4, lbl_805A0F88, 0);
        lbl_805A0F88 = 0;
    }
}