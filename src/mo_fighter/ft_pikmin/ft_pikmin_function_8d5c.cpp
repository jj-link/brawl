#pragma force_active on
extern "C" {
void fn_27_1999C4(void* ptr, int a, int b);
void fn_27_19BF3C(void* ptr, int a, int b);
void fn_27_150320(void* ptr, void* a, short b, void* c, void* d);
}

extern "C" void* fn_113_8D5C(void* self, void* arg2, int arg3)
{
    fn_27_1999C4(self, 0xA, 0);
    fn_27_19BF3C((char*)self + 0x584, 2, 0);
    fn_27_150320((char*)self + 0x5B8, arg2, (short)arg3, self, (void*)((unsigned long)self + 0x584));
    return self;
}
