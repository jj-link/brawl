#pragma force_active on
extern "C" {
void fn_27_199F1C(void*, int, int);
void fn_27_6A244(void*, void*, void*);
}

extern "C" void* fn_123_7AB8(void* self, void* arg)
{
    fn_27_199F1C(self, 7, 0);
    fn_27_6A244((char*)self + 0x178, arg, self);
    return self;
}
