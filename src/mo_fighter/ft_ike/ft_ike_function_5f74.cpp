#pragma force_active on
extern "C" {
void fn_27_CC060(void*, int, int);
void fn_27_2556C(void*, void*, void*, void*, void*);
extern char lbl_27_bss_298[];
}

extern "C" void* fn_119_5F74(char* self, void* a, void* b)
{
    fn_27_CC060(self, 1, 0);
    fn_27_2556C(self + 0x50, a, self, b, lbl_27_bss_298);
    return self;
}
