#pragma force_active on
extern void fn_801DD2A0(unsigned int);
extern void* fn_801DCF5C(short, void (*)(short, void *));
extern void fn_801DD320(unsigned int);
extern void fn_8025F99C(int, void *);
extern void fn_8025F9C0(short, void *);
extern void (*lbl_805A0E6C)(int, void *);

void fn_8025FA40(void)
{
    fn_801DD2A0(0x18000);
    fn_801DD2A0(0x40);
    lbl_805A0E6C = fn_8025F99C;
    fn_801DCF5C(0x19, fn_8025F9C0);
    fn_801DD320(0x40);
}
