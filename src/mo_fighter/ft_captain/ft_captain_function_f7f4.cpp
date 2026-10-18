#pragma force_active on
extern "C" {
void free__13gfHeapManagerFPv(void*);
extern void* lbl_100_bss_268;
extern void* lbl_100_bss_2D0;

void fn_100_F7F4() {
    if (lbl_100_bss_268) {
        free__13gfHeapManagerFPv(lbl_100_bss_268);
        lbl_100_bss_268 = 0;
    }
    if (lbl_100_bss_2D0) {
        free__13gfHeapManagerFPv(lbl_100_bss_2D0);
        lbl_100_bss_2D0 = 0;
    }
}
}
