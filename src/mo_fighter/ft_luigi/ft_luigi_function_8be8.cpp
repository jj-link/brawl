#pragma force_active on
struct FtObj {
    char pad[0xc];
    int *table;
};

extern "C" void fn_99_8BE8(FtObj *self, int value, int index) {
    self->table[index] += value;
}
