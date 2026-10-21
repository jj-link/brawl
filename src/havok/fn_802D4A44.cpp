#pragma force_active on
#include <types.h>

class Object;

extern "C" {

s32 fn_802D4890();
void fn_802D46F4(Object* p);
void fn_802D47E0(Object* p);
extern const char lbl_804109A8[];

struct lbl_80532820_type {
    const char* field0;
    void* field4;
    void* field8;
    s32 fieldC;
};
extern struct lbl_80532820_type lbl_80532820;

void fn_802D4A44(void) {
    s32 val = fn_802D4890();
    lbl_80532820.field0 = lbl_804109A8;
    lbl_80532820.field4 = &fn_802D46F4;
    lbl_80532820.field8 = &fn_802D47E0;
    lbl_80532820.fieldC = val;
}

}

__declspec(section ".ctors") extern void* const fn_802D4A44_ctor = (void*)fn_802D4A44;
