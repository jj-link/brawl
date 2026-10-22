#pragma force_active on
extern "C" {
extern char lbl_80410A04[];
extern char lbl_80410A18[];
extern char lbl_80532868[];
extern char lbl_8053288C[];
void fn_8027C808(void* p, void* a, void* b, unsigned c, unsigned d, unsigned e, unsigned f, unsigned g, void* h, unsigned i, unsigned j);

void fn_802D4E0C(void) {
    fn_8027C808(lbl_80532868, lbl_80410A18, 0, 4, 0, 1, 0, 0, 0, 0, 0);
    fn_8027C808(lbl_8053288C, lbl_80410A18 + 0x11, lbl_80532868, 8, 0, 0, 0, 0, lbl_80410A04, 1, 0);
}
}

__declspec(section ".ctors") extern void* const fn_802D4E0C_ctor = (void*)fn_802D4E0C;
