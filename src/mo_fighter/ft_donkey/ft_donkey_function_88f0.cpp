#pragma force_active on
// fn_92_88F0 initializes a command-resource block for the ft_donkey module.
// Layout: calcArea at +0x00 (initialized via fn_27_197FD4 with kind 3),
// workCalc at +0x48 (cleared via fn_27_198148), mediator at +0xA4
// (constructed via fn_27_B7E20 with the singletons lbl_27_bss_2BA4 and
// lbl_27_bss_2BCC). The block pointer is returned unchanged.

struct FtDonkeyCommandResources {
    unsigned char calcArea[0x48];  // +0x00: calculator initialized through fn_27_197FD4
    unsigned char workCalc[0x5C];  // +0x48: calculator cleared through fn_27_198148
    unsigned char mediator[0x40];  // +0xA4: mediator block constructed through fn_27_B7E20
};

extern "C" {
void fn_27_197FD4(void* calculator, int kind, int param);
void fn_27_198148(void* calculator, int param);
void fn_27_B7E20(void* mediator, void* context, void* owner, void* workCalc,
                 int index, void* singletons, void* pickTransactor);

extern unsigned char lbl_27_bss_2BA4[0xC];
extern unsigned char lbl_27_bss_2BCC[0xC];
}

extern "C" FtDonkeyCommandResources* fn_92_88F0(FtDonkeyCommandResources* resources,
                                                void* context, int index) {
    fn_27_197FD4(resources, 3, 0);
    fn_27_198148(&resources->workCalc, 0);
    fn_27_B7E20(&resources->mediator, context, resources, &resources->workCalc,
                index, lbl_27_bss_2BA4, lbl_27_bss_2BCC);
    return resources;
}
