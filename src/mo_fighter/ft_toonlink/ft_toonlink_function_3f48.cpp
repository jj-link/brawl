#pragma force_active on
extern "C" void fn_27_1999C4(void* a, int b, int c);
extern "C" void fn_27_19BF3C(void* a, int b, int c);
extern "C" void fn_27_150320(void* a, void* b, short c, void* d, void* e);

extern "C" {
void* fn_121_3F48(void* self, void* arg, int arg2);
}

void* fn_121_3F48(void* self, void* arg, int arg2)
{
    fn_27_1999C4(self, 10, 0);
    fn_27_19BF3C((void*)((int)self + 0x584), 2, 0);
    fn_27_150320((char*)self + 0x5b8, arg, (short)arg2, self, (char*)self + 0x584);
    return self;
}
