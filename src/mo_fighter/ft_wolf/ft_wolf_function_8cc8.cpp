#pragma force_active on
extern "C" void fn_27_1999C4(void* a, int b, int c);
extern "C" void fn_27_19BF3C(void* a, int b, int c);
extern "C" void fn_27_150320(void* a, void* b, short c, void* d, void* e);

extern "C" {
void* fn_125_8CC8(void* self, void* arg, short arg2)
{
    fn_27_1999C4(self, 10, 0);
    fn_27_19BF3C((char*)self + 0x584, 2, 0);
    fn_27_150320((char*)self + 0x5b8, arg, arg2, self, (void*)((int)self + 0x584));
    return self;
}
}
