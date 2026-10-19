#pragma force_active on
extern "C" {
void fn_27_D2FF0(void* self, int a, int b);
void* fn_27_61454(void* self, void* p, void* q, void* r, void* s, int t);
extern char lbl_27_bss_4694[];
extern char lbl_27_bss_46AC[];
}

extern "C" void* fn_108_8AC4(void* self, void* a, int b)
{
    fn_27_D2FF0(self, 1, 0);
    fn_27_61454((char*)self + 0xac, a, self, lbl_27_bss_4694, lbl_27_bss_46AC, b);
    return self;
}
