#pragma force_active on
struct LucasArray4 {
    unsigned int vtable;
    unsigned int arr[4][4];
};

extern "C" LucasArray4 lbl_114_data_8268;

extern "C" void fn_114_10DD4(LucasArray4** dst)
{
    *dst = &lbl_114_data_8268;
}
