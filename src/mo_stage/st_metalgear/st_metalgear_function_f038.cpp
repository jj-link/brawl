#pragma force_active on
extern "C" float fn_71_F038(const unsigned char* self, unsigned int index)
{
    float* arr = *(float**)(self + 0x520);
    return arr[index];
}
