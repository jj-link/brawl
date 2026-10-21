#pragma force_active on
extern void fn_8026D810(void);
extern void fn_8026D978(void);
extern void fn_8026DAE0(void);

void fn_8026D7BC(void *self, int arg1)
{
    switch (arg1) {
    case 0:
        *(void (**)(void))((char *)self + 0x28) = fn_8026D810;
        return;
    case 2:
        *(void (**)(void))((char *)self + 0x28) = fn_8026D978;
        return;
    case 1:
        *(void (**)(void))((char *)self + 0x28) = fn_8026DAE0;
        return;
    }
}
