#pragma force_active on
struct Fn113Owner;

extern "C" void fn_27_13646C(void);
extern "C" void fn_113_25698(Fn113Owner* self, int a, int b, int c);

extern "C" void fn_113_C4E0(Fn113Owner* self, int a, int b)
{
    fn_27_13646C();
    fn_113_25698((Fn113Owner*)((char*)self + 0x1FD08), a, b, 0);
}
