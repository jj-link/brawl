#pragma force_active on
extern "C" void fn_27_1999C4(void*, int, int);
extern "C" void fn_27_19BF3C(void*, int, int);
extern "C" void fn_27_150320(void*, void*, short, void*, void*);

extern "C" {
void* fn_93_3F48(char* self, void* arg2, short arg3)
{
    fn_27_1999C4(self, 10, 0);
    fn_27_19BF3C(self + 0x584, 2, 0);
    fn_27_150320(self + 0x5B8, arg2, arg3, self, self + 0x584);
    return self;
}
}
