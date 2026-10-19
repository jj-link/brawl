#pragma force_active on
extern "C" void fn_27_1999C4(void*, int, int);
extern "C" void fn_27_19BF3C(void*, int, int);
extern "C" void fn_27_150320(void*, void*, short, void*, void*);

extern "C" void* fn_123_7B0C(void* self, void* arg, short arg2)
{
    fn_27_1999C4(self, 10, 0);

    char* object = (char*)self;
    fn_27_19BF3C(object + 0x584, 2, 0);
    fn_27_150320(object + 0x5B8, arg, arg2, self, object + 0x584);

    return self;
}
