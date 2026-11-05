#include <gr/gr_gimmick.h>

#pragma force_active on

typedef void (grGimmick::*Handler)(float);

struct Table {
    Handler entries[4];
};

extern "C" const Table lbl_40_rodata_5F8;

extern "C" void fn_40_31E1C(grGimmick* self, float delta) {
    unsigned char* child = *(unsigned char**)((char*)self + 0xCC);
    if (child != 0 && (int)child[0x14C] == 1) {
        *(int*)((char*)self + 0x168) = 1;
    }

    Table table = lbl_40_rodata_5F8;
    (self->*table.entries[*(int*)((char*)self + 0x168)])(delta);
    self->grGimmick::update(delta);
    self->grGimmick::updateCallback(0);
}
