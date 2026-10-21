#pragma force_active on
struct Object {
    int unknown;
    int index;
};

typedef void (Object::*Callback)();

struct Table {
    Callback entries[4];
};

extern const Table lbl_27_rodata_4358;

extern "C" void fn_27_26B02C(Object* self) {
    Table table = lbl_27_rodata_4358;
    (self->*table.entries[self->index])();
}
