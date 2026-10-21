#pragma force_active on
extern void fn_8026B750(void);
extern void fn_8026B8B4(void);
extern void fn_8026BA18(void);

void fn_8026B6FC(char *self, int state)
{
    switch (state) {
    case 0:
        *(void (**)(void))(self + 0x24) = fn_8026B750;
        break;
    case 2:
        *(void (**)(void))(self + 0x24) = fn_8026B8B4;
        break;
    case 1:
        *(void (**)(void))(self + 0x24) = fn_8026BA18;
        break;
    }
}
