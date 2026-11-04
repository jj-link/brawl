#include <ft/fighter.h>
#pragma force_active on

extern const char lbl_27_data_248[];
extern const char lbl_27_data_69C0[];

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" int fn_27_111364(ftOwner*);
extern "C" void fn_27_3A963C(void*, unsigned int, void*, int, float);

extern "C" int fn_27_3A5C74(void* unused, void* a, void* b, void* c, float f) {
    Fighter* fighter = (Fighter*)__dynamic_cast(
        *(void**)((char*)b + 8), 0x3c,
        lbl_27_data_69C0, lbl_27_data_248, 1);

    unsigned int taskId = fighter->m_taskId;
    int ownerId = fn_27_111364(fighter->getOwner());
    fn_27_3A963C(a, taskId, c, ownerId, f);
    return 1;
}