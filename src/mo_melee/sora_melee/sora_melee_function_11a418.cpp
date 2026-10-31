#pragma force_active on
extern "C" void fn_27_11967C(void*, int, unsigned int, unsigned int, unsigned int, unsigned int);

extern "C" void fn_27_11A418(void* self, unsigned int arg)
{
    if (*((unsigned char*)self + 0x3C) == 1) {
        fn_27_11967C(self, 0, *((unsigned int*)self + 0x11), *((unsigned int*)self + 0x12), arg, 0xFFFFFFFF);
    }
}