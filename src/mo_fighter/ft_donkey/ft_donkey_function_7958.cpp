#pragma force_active on
struct DonkeyCommandResources {
    unsigned char area[0xAC];
    unsigned char sub[0x40];
};

extern "C" {
void fn_27_D2FF0(void* calculator, int kind, int param);
void fn_27_61454(void* mediator, void* context, void* owner, void* a, void* b, void* c);
extern unsigned char lbl_27_bss_4694[0xC];
extern unsigned char lbl_27_bss_46AC[0x4];
}

extern "C" DonkeyCommandResources* fn_92_7958(DonkeyCommandResources* resources, void* context, void* param) {
    fn_27_D2FF0(resources, 1, 0);
    fn_27_61454(&resources->sub, context, resources, lbl_27_bss_4694, lbl_27_bss_46AC, param);
    return resources;
}
