#pragma force_active on
extern void fn_80282CD4(void *, void *, void *);
extern void fn_80282FE4(void *, void *, void *);

void fn_80283A68(void *arg0, void *arg1) {
    char buf[0x30] __attribute__((aligned(16)));

    fn_80282FE4(buf, arg0, arg1);
    fn_80282CD4(arg0, arg1, buf);
}
