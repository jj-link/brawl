#pragma force_active on
extern "C" void fn_27_19A05C(void*, int, int);
extern "C" void fn_27_6A244(void*, void*, void*);

extern "C" void* fn_96_43EC(void* self, void* arg)
{
    fn_27_19A05C(self, 8, 0);
    fn_27_6A244((char*)self + 0x1ac, arg, self);
    return self;
}
