#pragma force_active on
struct DededeTable {
    unsigned char _0x00[0x0C];
    void** _0x0C;
};

extern "C" void* fn_117_A878(DededeTable* self, int index) {
    return self->_0x0C[index];
}
