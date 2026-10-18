#pragma force_active on
extern "C" {
void fn_27_C1054(void *self, unsigned int arg);

void fn_27_BF9D0(char *self, unsigned int arg)
{
    if (arg == 1) {
        self += 0xb8;
    } else {
        self += 0x30;
    }
    fn_27_C1054(self, arg);
}
}
