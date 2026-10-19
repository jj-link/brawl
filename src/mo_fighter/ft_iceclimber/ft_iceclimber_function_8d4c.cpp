#pragma force_active on
extern "C" void fn_27_199F1C(void*, int, int);
extern "C" void fn_27_6A244(void*, void*, void*);

extern "C" void* fn_105_8D4C(void* self, void* arg)
{
    fn_27_199F1C(self, 7, 0);
    fn_27_6A244((char*)self + 0x178, arg, self);
    return self;
}
