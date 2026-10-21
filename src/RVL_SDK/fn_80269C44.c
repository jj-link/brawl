#pragma force_active on
extern void fn_80269EA4(void);
extern void fn_8026A00C(void);
extern void fn_8026A174(void);

void fn_80269C44(void *self, int arg)
{
    switch (arg) {
    case 0:
        *(void (**)(void))((char *)self + 0x28) = fn_80269EA4;
        return;
    case 2:
        *(void (**)(void))((char *)self + 0x28) = fn_8026A00C;
        return;
    case 1:
        *(void (**)(void))((char *)self + 0x28) = fn_8026A174;
        return;
    }
}
