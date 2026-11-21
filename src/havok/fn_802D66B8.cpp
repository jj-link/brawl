#pragma force_active on

struct Vec4 {
    float x, y, z, w;
};

extern "C" void fn_802D66B8(char* self, unsigned short* indices, int count, Vec4* out) {
    count--;
    char* base = self + 16;
    while (count-- >= 0) {
        unsigned int offset = *indices++;
        Vec4* t5_16 = (Vec4*)(base + offset);
        *out = *t5_16;
        *(unsigned int*)&out->w = offset;
        ++out;
    }
}
