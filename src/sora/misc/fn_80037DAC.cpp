#pragma force_active on
extern "C" {
char* strcat(char* dst, const char* src);
extern char lbl_804953D0[72];
extern char lbl_80423380[];
}

extern "C" void fn_80037DAC(void) {
    lbl_804953D0[0] = 0;
    strcat(lbl_804953D0, lbl_80423380);
}

__declspec(section ".ctors") extern void* const fn_80037DAC_ctor = (void*)fn_80037DAC;
