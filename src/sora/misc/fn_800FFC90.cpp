#include <ut/ut_list.h>
#pragma force_active on
struct Object {
    utListNode node;
    utList* list;
    void** link;
    void* pad;
    void* vtable;
};
extern "C" char lbl_8045CCC0[];
extern "C" utList lbl_8049E560;
extern "C" void __dl__FPv(void*);
extern "C" Object* fn_800FFC90(Object* self, int deleting) {
    if (self != 0) {
        void** link = self->link;
        self->vtable = lbl_8045CCC0;
        if (self != 0 && link != 0) {
            self->link = 0;
            *link = 0;
        }
        if (self != 0) {
            lbl_8049E560.removeExist(&self->node);
            self->list = 0;
            if (self != 0) {
                if (self->list != 0) {
                    ((utList*)0)->removeExist(&self->node);
                    self->list = 0;
                }
            }
        }
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}