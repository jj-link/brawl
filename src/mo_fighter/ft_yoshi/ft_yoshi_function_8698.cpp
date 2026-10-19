#pragma force_active on
extern "C" {
void fn_27_CC060(void*, int, int);
void fn_27_2556C(void*, void*, void*, void*, void*);
extern unsigned char lbl_27_bss_298[];

void* fn_95_8698(void* self, void* a, void* b)
{
    fn_27_CC060(self, 1, 0);
    fn_27_2556C((char*)self + 0x50, a, self, b, lbl_27_bss_298);
    return self;
}
}
