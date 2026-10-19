#pragma force_active on
extern "C" void fn_27_199DDC(void*, int, int);
extern "C" void fn_27_6A244(void*, void*, void*);

extern "C" void* fn_104_85E0(void* self, void* arg)
{
    fn_27_199DDC(self, 6, 0);
    fn_27_6A244(static_cast<char*>(self) + 0x144, arg, self);
    return self;
}
