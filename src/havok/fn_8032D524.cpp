#pragma force_active on
extern "C" {
extern char lbl_804147C0[];
extern char lbl_804147F8[];
extern char lbl_80414820[];
extern char lbl_80533360[];
extern char lbl_80533384[];
void fn_8027C808(void* p, void* a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f, unsigned g, void* h, unsigned i, unsigned j);

void fn_8032D524() {
    fn_8027C808(lbl_80533360, lbl_80414820, 0, 8, 0, 0, 0, 0, lbl_804147C0, 2, 0);
    fn_8027C808(lbl_80533384, lbl_80414820 + 0x1C, 0, 0xC, 0, 0, 0, 0, lbl_804147F8, 2, 0);
}
}

__declspec(section ".ctors") extern void* const fn_8032D524_ctor = (void*)fn_8032D524;
