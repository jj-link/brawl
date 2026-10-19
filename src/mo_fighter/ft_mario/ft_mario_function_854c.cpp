#pragma force_active on
struct MarioCommandResources {
    unsigned char calcArea[0x48];
    unsigned char workCalc[0x5C];
    unsigned char mediator[0x6C];
};

extern "C" {
void fn_27_197FD4(void*, int, int);
void fn_27_198148(void*, int);
void fn_27_B7E20(void*, void*, void*, void*, int, void*, void*);
extern unsigned char lbl_27_bss_2BA4[0xC];
extern unsigned char lbl_27_bss_2BCC[0xC];

MarioCommandResources* fn_91_854C(MarioCommandResources* resources, void* context, int index) {
    fn_27_197FD4(resources, 3, 0);
    fn_27_198148(&resources->workCalc, 0);
    fn_27_B7E20(&resources->mediator, context, resources, &resources->workCalc,
                index, lbl_27_bss_2BA4, lbl_27_bss_2BCC);
    return resources;
}
}
