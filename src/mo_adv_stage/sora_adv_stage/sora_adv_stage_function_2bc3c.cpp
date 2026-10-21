#pragma force_active on

struct Gimmick {
    char pad[0x170];
    int index;
};

typedef void (Gimmick::*Handler)();

struct Table {
    Handler entries[4];
};

extern "C" {
extern const Table lbl_40_rodata_4B8;
void update__9grGimmickFf(Gimmick*, float);
void updateCallback__9grGimmickFUl(Gimmick*, unsigned long);

void fn_40_2BC3C(Gimmick* self, float delta) {
    Table table = lbl_40_rodata_4B8;
    (self->*table.entries[self->index])();
    update__9grGimmickFf(self, delta);
    updateCallback__9grGimmickFUl(self, 0);
}
}
