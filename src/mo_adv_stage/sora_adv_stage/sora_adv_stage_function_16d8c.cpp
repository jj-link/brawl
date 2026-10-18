#pragma force_active on
extern "C" void fn_40_15C74(void);

extern "C" void fn_40_16D8C(unsigned char *self)
{
    self[6] = 0;
    fn_40_15C74();
}
