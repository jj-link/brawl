#pragma force_active on
// fn_96_9C14 initializes the command-resource block used by the Kirby
// fighter module, mirroring the soArrayVectorCalculator/mediator construction
// pattern of the other fighter modules: the primary calculator area (+0x00)
// is post-initialized through fn_27_19824C with kind 7 (and an unread trailing
// zero argument), the second calculator area at +0x98 is re-armed through
// fn_27_198148, and the mediator block at +0xF4 is constructed through
// fn_27_B7E20, which receives the caller's context pointer, this owning
// block, the +0x98 calculator, the index argument and the module singletons
// lbl_27_bss_2BA4 / lbl_27_bss_2BCC.  The block pointer is returned
// unchanged.

// TU-local view of the command-resource block covering exactly the regions
// this unit initializes (the block continues past +0x160 in the original).
struct KirbyCommandResources {
    unsigned char calcArea[0x98]; // +0x00: soArrayVectorCalculator area initialized through fn_27_19824C
    unsigned char workCalc[0x5C]; // +0x98: second calculator area cleared through fn_27_198148 and handed to the mediator initializer
    unsigned char mediator[0x6C]; // +0xF4: mediator block constructed through fn_27_B7E20
};

extern "C" {
void fn_27_19824C(void* calculator, int kind, int param);
void fn_27_198148(void* calculator, int param);
void fn_27_B7E20(void* mediator, void* context, void* owner, void* workCalc,
                 int index, void* singletons, void* pickTransactor);

extern unsigned char lbl_27_bss_2BA4[0xC];
extern unsigned char lbl_27_bss_2BCC[0xC];
}

extern "C" KirbyCommandResources* fn_96_9C14(KirbyCommandResources* resources,
                                             void* context, int index) {
    fn_27_19824C(resources, 7, 0);
    fn_27_198148(&resources->workCalc, 0);
    fn_27_B7E20(&resources->mediator, context, resources, &resources->workCalc,
                index, lbl_27_bss_2BA4, lbl_27_bss_2BCC);
    return resources;
}
