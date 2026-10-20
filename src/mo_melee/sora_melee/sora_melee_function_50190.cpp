#pragma force_active on
extern "C" void fn_8015BFB4(void*, void*);

extern "C" void fn_27_50190(char* self, int idx)
{
    fn_8015BFB4(self + 0xa8, *(char**)(self + 0xa4) + idx * 0x34);
}
