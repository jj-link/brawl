#pragma force_active on
extern "C" void fn_27_CB410(void* self, int a, int b);
extern "C" void fn_27_B215C(void* sub, int a, void* self, int b, int c, int d);

extern "C" {
void* fn_113_8DCC(void* self, int p1, int p2, int p3, int p4)
{
    fn_27_CB410(self, 1, 0);
    fn_27_B215C((char*)self + 0x50, p1, self, p2, p3, p4);
    return self;
}
}
