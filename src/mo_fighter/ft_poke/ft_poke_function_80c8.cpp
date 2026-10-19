#pragma force_active on
extern "C" void fn_27_711E4(void*, short, void*);
extern "C" void* fn_27_1AB96C(void*, unsigned char);

extern "C" void* fn_116_80C8(char* self, short id)
{
    fn_27_711E4(self, id, self + 0x24);
    fn_27_1AB96C(self + 0x24, 0);
    return self;
}
