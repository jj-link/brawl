#include <types.h>
#pragma force_active on

// TU-local view of the command-resource block covering exactly the regions
// this unit initializes. The primary calculator lands at +0x00, the second
// calculator area at +0x48, and the mediator block at +0xA4.
struct MetaKnightCommandResources {
    unsigned char calcArea[0x48]; // +0x00: soArrayVectorCalculator area initialized through fn_27_197FD4
    unsigned char workCalc[0x5C]; // +0x48: second calculator area cleared through fn_27_198148 and handed to the mediator initializer
    unsigned char mediator[0x6C]; // +0xA4: mediator block constructed through fn_27_B7E20
};

extern "C" {
void fn_27_197FD4(void* calculator, int kind, int param);
void fn_27_198148(void* calculator, int param);
void fn_27_B7E20(void* mediator, void* context, void* owner, void* workCalc,
                 int index, void* singletons, void* pickTransactor);

extern unsigned char lbl_27_bss_2BA4[0xC];
extern unsigned char lbl_27_bss_2BCC[0xC];
}

extern "C" MetaKnightCommandResources* fn_111_787C(MetaKnightCommandResources* resources,
                                                   void* context, int index) {
    fn_27_197FD4(resources, 3, 0);
    fn_27_198148(&resources->workCalc, 0);
    fn_27_B7E20(&resources->mediator, context, resources, &resources->workCalc,
                index, lbl_27_bss_2BA4, lbl_27_bss_2BCC);
    return resources;
}
