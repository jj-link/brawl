#pragma force_active on
typedef struct WorkHolder {
    unsigned char pad[0xc];
    unsigned int* table;
} WorkHolder;

extern "C" void fn_104_AB48(WorkHolder* self, unsigned int value, unsigned int index) {
    self->table[index] = value;
}
