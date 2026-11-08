#pragma force_active on

struct Arg3 {
    char pad0[0x20];
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    char pad34[4];
    int f38;
};

extern const float lbl_805A45C4;

extern "C" void fn_80306EFC(void* arg0, float* out, const unsigned char* index, Arg3* arg3)
{
    if (arg3->f38 <= 2) {
        float zero = lbl_805A45C4;
        out[3] = zero;
        int byteOffset = *index * 4;
        out[2] = zero;
        out[1] = zero;
        out[0] = zero;
        *(float*)((char*)out + byteOffset) = -arg3->f30;
        return;
    }

    if (arg3->f38 <= 6) {
        float* vector = (float*)((char*)arg0 + 0x20);
        int offset = (*index - 4) * 4;
        float scale = -arg3->f30;

        out[0] = scale * *(vector += offset);
        out[1] = scale * vector[1];
        out[2] = scale * vector[2];
        out[3] = scale * vector[3];
        return;
    }

    out[0] = arg3->f20;
    out[1] = arg3->f24;
    out[2] = arg3->f28;
    out[3] = arg3->f2c;
}
