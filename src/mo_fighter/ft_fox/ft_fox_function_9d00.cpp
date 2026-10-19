#pragma force_active on
// fn_97_9D00 initializes the Fox command-resource block (same shape as the
// DeDeDe block in ft_dedede_function_8714.cpp): the primary calculator at
// +0x00 is set up through fn_27_197FD4 (kind 3), the work calculator at
// +0x48 is re-armed through fn_27_198148, and the mediator at +0xa4 is
// constructed through fn_27_B7E20 with the module's singleton objects. The
// block pointer is returned unchanged.

struct FoxCommandResources {
    unsigned char calcArea[0x48];   // +0x00: primary calculator area initialized through fn_27_197FD4
    unsigned char workCalc[0x5C];   // +0x48: second calculator area cleared through fn_27_198148
    unsigned char mediator[0x6C];   // +0xa4: mediator block constructed through fn_27_B7E20
};

extern "C" {
void fn_27_197FD4(void* calculator, int kind, int param);
void fn_27_198148(void* calculator, int param);
void fn_27_B7E20(void* mediator, void* context, void* owner, void* workCalc,
                 int index, void* singletons, void* pickTransactor);

extern unsigned char lbl_27_bss_2BA4[0xC];
extern unsigned char lbl_27_bss_2BCC[0xC];
}

extern "C" FoxCommandResources* fn_97_9D00(FoxCommandResources* resources,
                                           void* context, int index) {
    fn_27_197FD4(resources, 3, 0);
    fn_27_198148(&resources->workCalc, 0);
    fn_27_B7E20(&resources->mediator, context, resources, &resources->workCalc,
                index, lbl_27_bss_2BA4, lbl_27_bss_2BCC);
    return resources;
}
