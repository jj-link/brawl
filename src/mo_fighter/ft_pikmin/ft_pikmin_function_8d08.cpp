#pragma force_active on
extern "C" void fn_27_199C9C(void*, int, int);
extern "C" void fn_27_6A244(void*, void*, void*);

extern "C" {
void* fn_113_8D08(void* self, void* arg);
}

void* fn_113_8D08(void* self, void* arg)
{
    fn_27_199C9C(self, 0xd, 0);
    fn_27_6A244((char*)self + 0x2b0, arg, self);
    return self;
}
