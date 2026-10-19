#pragma force_active on
extern "C" void fn_27_5CDB8(void* p);
extern "C" void fn_41_FCC0(void* p);

extern "C" void fn_41_FD04(void* p)
{
    fn_27_5CDB8(p);
    fn_41_FCC0(p);
    *(int*)((char*)p + 0xdc) = -1;
}
