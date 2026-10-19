#pragma force_active on
typedef unsigned char Byte;
typedef unsigned int Word;

extern "C" {
void fn_27_CC060(void*, int, int);
void fn_27_2556C(void*, void*, void*, Word, void*);
extern Byte lbl_27_bss_298[];
}

extern "C" void* fn_113_8784(void* self, void* a, Word b)
{
    fn_27_CC060(self, 1, 0);
    fn_27_2556C((Byte*)self + 0x50, a, self, b, lbl_27_bss_298);
    return self;
}
