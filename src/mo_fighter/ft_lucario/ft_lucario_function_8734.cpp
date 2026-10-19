#pragma force_active on
extern "C" void fn_27_197FD4(void* calculator, int kind, int param);
extern "C" void fn_27_198148(void* calculator, int param);
extern "C" void fn_27_B7E20(void* mediator, void* context, void* owner, void* workCalc, void* arg4, void* arg5, void* arg6);
extern unsigned char lbl_27_bss_2BA4[0xC];
extern unsigned char lbl_27_bss_2BCC[0xC];

extern "C" void* fn_118_8734(void* self, void* context, void* param) {
    unsigned char* storage = static_cast<unsigned char*>(self);
    fn_27_197FD4(self, 3, 0);
    fn_27_198148(storage + 0x48, 0);
    fn_27_B7E20(storage + 0xA4, context, self, storage + 0x48, param, lbl_27_bss_2BA4, lbl_27_bss_2BCC);
    return self;
}
