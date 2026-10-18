#pragma force_active on
struct UnknownUnk {
    void *field;
};

extern "C" struct UnknownUnk lbl_102_data_7C44;

extern "C" void fn_102_18760(UnknownUnk *object)
{
    object->field = &lbl_102_data_7C44;
}
