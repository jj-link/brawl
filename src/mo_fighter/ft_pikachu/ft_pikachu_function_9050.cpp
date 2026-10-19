#pragma force_active on
extern "C" {
void fn_27_197FD4(void* calculator, int kind, int param);
void fn_27_198148(void* calculator, int param);
void fn_27_B7E20(void* mediator, void* context, void* owner, void* workCalc,
                 int index, void* singletons, void* pickTransactor);

extern unsigned char lbl_27_bss_2BA4[0xC];
extern unsigned char lbl_27_bss_2BCC[0xC];
}

extern "C" void* fn_98_9050(char* self, void* context, int index) {
    fn_27_197FD4(self, 3, 0);
    fn_27_198148(self + 0x48, 0);
    fn_27_B7E20(self + 0xa4, context, self, self + 0x48, index,
                lbl_27_bss_2BA4, lbl_27_bss_2BCC);
    return self;
}
