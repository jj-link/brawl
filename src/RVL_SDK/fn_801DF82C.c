#pragma force_active on
extern char lbl_804689E0[];
extern char lbl_80468BEC[];
void fn_801D8690(const char* file, int line, const char* msg, ...);

void OSResetSystem(unsigned long arg0, unsigned long arg1, unsigned long arg2) {
#pragma unused(arg0)
#pragma unused(arg1)
#pragma unused(arg2)
    fn_801D8690(lbl_804689E0, 0x464, lbl_80468BEC);
}
