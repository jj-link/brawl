#pragma force_active on
struct Fn41Obj {
    char pad[0x1c];
    int *table;
};

extern "C" {
void fn_41_C170(Fn41Obj *self, int idx) {
    self->table[idx] = 0;
}
}
