#pragma force_active on
#pragma opt_propagation off

extern "C" void fn_800FABEC(void*);
extern "C" void fn_800FAC58(void*, const void*, int, int);
extern int lbl_2_data_4D30[];

extern "C" void fn_2_3A940(char* self) {
    unsigned long base = (unsigned long)lbl_2_data_4D30;
    const void* p = (void*)(base + 0x150);

    fn_800FABEC(self + 0x248);
    *(int*)(self + 0x234) = 0;
    self[0x260] = 0;
    fn_800FAC58(self + 0x248, p, 0x2B, 0);

    const void* p2 = (void*)(base + 0x178);
    fn_800FABEC(self + 0x27C);
    *(int*)(self + 0x268) = 0;
    self[0x294] = 0;
    fn_800FAC58(self + 0x27C, p2, 0x2B, 0);

    fn_800FAC58(self + 0x29C, (void*)(base + 0x198), 0x2B, 0);
}
