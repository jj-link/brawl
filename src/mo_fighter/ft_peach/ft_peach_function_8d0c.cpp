#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_197FD4(void* calculator, int kind, int param);
void fn_27_198148(void* calculator, int param);
void fn_27_B7E20(void* mediator, void* context, void* owner, void* workCalc,
                 int index, void* singletons, void* pickTransactor);

extern unsigned char lbl_27_bss_2BA4[0xC];
extern unsigned char lbl_27_bss_2BCC[0xC];

struct Fn103Object {
    unsigned char calcArea[0x48];
    unsigned char workCalc[0x5C];
    unsigned char mediator[0x6C];
};

void* fn_103_8D0C(Fn103Object* object, void* context, int index) {
    fn_27_197FD4(object, 3, 0);
    fn_27_198148(&object->workCalc, 0);
    fn_27_B7E20(&object->mediator, context, object, &object->workCalc,
                index, lbl_27_bss_2BA4, lbl_27_bss_2BCC);
    return object;
}
}
