#pragma force_active on
extern "C" {

struct HalberdStore
{
    char pad_0[0x5b0];
    int field_5b0;
    char pad_5b4[4];
    int field_5b8;
};

void fn_57_A580(HalberdStore* self, int first, int second)
{
    self->field_5b0 = first;
    self->field_5b8 = second;
}

} // extern "C"
