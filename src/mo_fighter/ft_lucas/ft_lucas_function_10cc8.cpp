#pragma force_active on
struct LucasArrayAggregate {
    void* vtable;
    unsigned int cache[3];
    void* a;
    void* b;
    void* c;
};

extern "C" void fn_114_10CC8(LucasArrayAggregate* arrays)
{
    extern const unsigned char lbl_114_data_81B8[0x40];

    arrays->vtable = (void*)lbl_114_data_81B8;
}