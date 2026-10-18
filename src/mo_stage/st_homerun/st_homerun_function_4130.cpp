#pragma force_active on

extern "C" {

#pragma section ".rodata"

extern const float lbl_88_rodata_0[];

float fn_88_4130()
{
    const float* c = lbl_88_rodata_0;
    return c[0];
}

}
