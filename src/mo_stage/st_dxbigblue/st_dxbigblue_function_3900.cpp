#pragma force_active on
extern "C" {

extern float lbl_81_rodata_70;

int fn_81_3900(void* ths, float* p)
{
    char* base = (char*)ths;
    if (p == 0) return 0;
    char* list = *(char**)(base + 0x9c);
    if (list == 0) return 0;
    unsigned int count = *(unsigned int*)(list + 0x18);
    float c = lbl_81_rodata_70;
    for (unsigned int i = 0; i != count; i++) {
        unsigned int idx = *(unsigned char*)(base + 0xa9a) + i;
        if (idx >= 0x1e) idx -= 0x1e;
        unsigned char mdl = *(unsigned char*)(base + 0xa7c + idx);
        float f2 = *(float*)(base + 0x378 + mdl * 0x3c);
        float val = *p;
        if (val > f2 - c && val < c + f2)
            return 1;
    }
    return 0;
}

}
