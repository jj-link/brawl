#pragma force_active on
struct ftPokeWork {
    char pad_00[0x0c];
    void **m_items;
};

extern "C" void *fn_116_A984(ftPokeWork *self, unsigned int index) {
    return self->m_items[index];
}
