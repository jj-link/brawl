#pragma force_active on
extern "C" {
void fn_801473C4(void* arg);
void fn_800CCF0C(void* arg)
{
    ((int*)arg)[0x412] = 0;
    ((int*)arg)[0x413] = 0;
    fn_801473C4(arg);
}
}
