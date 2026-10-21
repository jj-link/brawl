#pragma force_active on
extern unsigned char lbl_8052D5A8[];
extern void* memset(void* dst, int c, unsigned long n);
extern void fn_80251E50(void* self);

void fn_8025042C(void)
{
    unsigned char* p = lbl_8052D5A8;

    memset(p, 0, 0x418);
    p[0x65] = 1;
    p[0x414] = 5;
    fn_80251E50(p);
}
