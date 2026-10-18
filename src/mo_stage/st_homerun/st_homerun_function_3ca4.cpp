#pragma force_active on
extern "C" unsigned int __cvt_fp2unsigned(float);

struct HomerunData
{
    unsigned char pad[0x5AC];
    float value;
};

extern float lbl_88_rodata_C;

extern "C" unsigned int fn_88_3CA4(HomerunData *data)
{
    return __cvt_fp2unsigned(lbl_88_rodata_C * data->value);
}
