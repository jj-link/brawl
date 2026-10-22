#pragma force_active on
extern unsigned char lbl_8052D5A8[];

typedef void (*FnPtr)(void);

extern void fn_80251ECC(void);
extern void fn_80251F58(void);
extern void fn_8025205C(void);
extern void fn_80252164(void);
extern void fn_8025226C(void);
extern void fn_80252270(void);
extern void fn_80252394(void);
extern void fn_80252634(void);
extern void fn_8024A304(int, FnPtr *);

void fn_80251E50(void)
{
    FnPtr *p = (FnPtr *)(lbl_8052D5A8 + 0x14);

    p[0] = fn_80251ECC;
    p[1] = fn_80251F58;
    p[2] = 0;
    p[3] = fn_8025205C;
    p[4] = fn_80252164;
    p[5] = fn_80252270;
    p[6] = 0;
    p[7] = fn_8025226C;
    p[8] = fn_80252394;
    p[9] = fn_80252634;

    fn_8024A304(3, p);
}
