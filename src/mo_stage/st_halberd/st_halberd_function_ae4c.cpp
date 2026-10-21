#pragma force_active on
struct HalberdData {
    unsigned int pad[2];
    unsigned int high : 4;
    unsigned int value : 4;
    unsigned int low : 24;
};

extern "C" void fn_57_AE4C(HalberdData* self, unsigned int value)
{
    self->value = value;
}
