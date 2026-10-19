#pragma force_active on
struct SamusCommandResources {
    unsigned char calcArea[0x48]; // +0x00
    unsigned char workCalc[0x5C]; // +0x48
    unsigned char mediator[0x6C]; // +0xA4
};

extern "C" {
void fn_27_197FD4(void* calculator, int kind, int param);
void fn_27_198148(void* calculator, int param);
void fn_27_B7E20(void* mediator, void* context, void* owner, void* workCalc,
                 int index, void* singletons, void* pickTransactor);

extern unsigned char lbl_27_bss_2BA4[0xC];
extern unsigned char lbl_27_bss_2BCC[0xC];
}

extern "C" SamusCommandResources* fn_94_8BF4(SamusCommandResources* resources,
                                             void* context, int index) {
    fn_27_197FD4(resources, 3, 0);
    fn_27_198148(&resources->workCalc, 0);
    fn_27_B7E20(&resources->mediator, context, resources, &resources->workCalc,
                index, lbl_27_bss_2BA4, lbl_27_bss_2BCC);
    return resources;
}
