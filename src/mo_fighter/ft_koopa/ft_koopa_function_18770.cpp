#pragma force_active on
extern "C" {
struct Func_102_R1_3 {
    void *vtable;
    unsigned long value;
};
}

extern "C" unsigned char lbl_102_data_7BC8[];

extern "C" void fn_102_18770(Func_102_R1_3 *arg)
{
    arg->vtable = lbl_102_data_7BC8;
}
