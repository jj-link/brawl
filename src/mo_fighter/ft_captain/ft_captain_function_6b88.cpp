struct FourBytes
{
    void *field_0;
    char field_4;
};

extern "C" {
#pragma force_active on
extern char lbl_100_data_2268[12];

void fn_100_6B88(FourBytes *object, int value)
{
    object->field_0 = (void *)&lbl_100_data_2268[0];
    object->field_4 = static_cast<char>(value);
}
}
