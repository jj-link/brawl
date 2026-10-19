#pragma force_active on
extern "C" void fn_27_CB410(void* self, int a, int b);
extern "C" void fn_27_B215C(void* p, void* a2, void* self, void* a3, void* a4, void* a5);

extern "C" char* fn_102_6E80(char* self, void* a2, void* a3, void* a4, void* a5)
{
    fn_27_CB410(self, 1, 0);
    fn_27_B215C(self + 0x50, a2, self, a3, a4, a5);
    return self;
}
