#pragma force_active on
struct U { unsigned int pad[2]; unsigned int f : 5; unsigned int : 27; };
extern "C" void fn_76_3DB4(U* arg1, unsigned int arg2)
{
    arg1->f = arg2;
}