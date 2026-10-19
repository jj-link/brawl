#pragma force_active on
extern "C" void fn_27_CB410(void*, int, int);
extern "C" void fn_27_B215C(void*, void*, void*, int, int, int);

extern "C" void* fn_109_7540(void* fighter, void* a, int b, int c, int d)
{
    fn_27_CB410(fighter, 1, 0);
    fn_27_B215C(static_cast<char*>(fighter) + 0x50, a, fighter, b, c, d);
    return fighter;
}
