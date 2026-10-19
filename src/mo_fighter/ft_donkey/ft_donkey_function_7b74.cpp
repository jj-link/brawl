#pragma force_active on
extern "C" {
void fn_27_CB410(void* self, int a, int b);
void fn_27_B215C(void* p, int a, void* self, int b, int c, int d);
}

extern "C" void* fn_92_7B74(void* self, int a, int b, int c, int d)
{
    fn_27_CB410(self, 1, 0);
    fn_27_B215C((char*)self + 0x50, a, self, b, c, d);
    return self;
}
