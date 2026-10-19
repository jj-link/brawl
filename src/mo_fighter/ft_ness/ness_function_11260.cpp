#pragma force_active on
struct NessRecord {
    unsigned int kind;
    unsigned char flag;
    unsigned char padding[3];
    void* first;
    void* second;
};

extern "C" void fn_101_11260(NessRecord* self, void* first, void* second)
{
    self->kind = 0x455;
    self->flag = 0;
    self->first = first;
    self->second = second;
}
