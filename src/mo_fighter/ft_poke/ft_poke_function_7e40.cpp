#pragma force_active on
extern "C" {
void fn_27_D2FF0(void* self, int a, int b);
void* fn_27_61454(void* a, void* b, void* c, void* d, void* e, void* f);
extern char lbl_27_bss_4694[];
extern char lbl_27_bss_46AC[];

void* fn_116_7E40(void* self, void* p2, void* p3)
{
    fn_27_D2FF0(self, 1, 0);
    fn_27_61454((char*)self + 0xac, p2, self, lbl_27_bss_4694, lbl_27_bss_46AC, p3);
    return self;
}
}
