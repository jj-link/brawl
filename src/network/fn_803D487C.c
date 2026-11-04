#pragma force_active on

extern int *fn_803CD2A8(void);
extern int fn_80204768(int, int, int);
extern void fn_803D6150(void);

void fn_803D487C(int arg0)
{
    int *p = fn_803CD2A8();
    p[0] = fn_80204768(arg0, 0x1F1E0, 0x20);
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    fn_803D6150();
}
