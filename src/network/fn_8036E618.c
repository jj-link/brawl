#pragma force_active on
extern void fn_8036A328(void **, void *, const char *);
extern void fn_8036A384(void **, void *, int);

extern char lbl_8048F500[0x16];
extern char lbl_8048F224[0x180];
extern char lbl_8059F7F8[5];
extern char lbl_8059F7E0[8];

int fn_8036E618(void **arg0, int arg1, int arg2)
{
    char *data = (char *)*arg0;

    fn_8036A328(arg0, data + 0x210, lbl_8048F500);
    fn_8036A384(arg0, data + 0x210, *(int *)(data + 0x198));
    fn_8036A328(arg0, data + 0x210, lbl_8048F224);
    fn_8036A384(arg0, data + 0x210, arg1);
    fn_8036A328(arg0, data + 0x210, lbl_8059F7F8);
    fn_8036A384(arg0, data + 0x210, arg2);
    fn_8036A328(arg0, data + 0x210, lbl_8059F7E0);
    return 0;
}
