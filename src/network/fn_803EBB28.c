#include <revolution/VF/pf_critical.h>
#pragma force_active on

struct PF_Critical {
    int field_0;
    int counter;
    int field_8;
    int field_c;
};

extern void fn_803EC418(int);

void PF_exitCritical(void* unk) {
    struct PF_Critical* c = (struct PF_Critical*)unk;
    c->counter--;
    if (c->counter != 0) {
        return;
    }
    c->field_c = 0;
    fn_803EC418(c->field_8);
}
