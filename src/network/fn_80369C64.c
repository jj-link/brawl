#pragma force_active on
extern void fn_80372DD8(char *dest, const char *src, unsigned long n);
extern void fn_8036A328(void **, void *, const char *);
extern void fn_8036A384(void **, void *, int);

extern char lbl_8059F640[5];
extern char lbl_8048ED24[0x5C];
extern char lbl_8059F684[4];
extern char lbl_8059F654[6];
extern char lbl_8059F688[8];

int fn_80369C64(void **arg0, int arg1, int arg2, const char *arg3)
{
    char buffer[0xDAD];
    char *data = (char *)*arg0;

    fn_80372DD8(buffer, arg3, 0xDAD);
    fn_8036A328(arg0, data + 0x210, lbl_8059F640);
    fn_8036A384(arg0, data + 0x210, arg2);
    fn_8036A328(arg0, data + 0x210, lbl_8048ED24);
    fn_8036A384(arg0, data + 0x210, *(int *)(data + 0x198));
    fn_8036A328(arg0, data + 0x210, lbl_8059F684);
    fn_8036A384(arg0, data + 0x210, arg1);
    fn_8036A328(arg0, data + 0x210, lbl_8059F654);
    fn_8036A328(arg0, data + 0x210, buffer);
    fn_8036A328(arg0, data + 0x210, lbl_8059F688);
    return 0;
}
