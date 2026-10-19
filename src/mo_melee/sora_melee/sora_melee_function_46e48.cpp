#pragma force_active on
struct Src {
    int pad0;
    int pad1;
    float f0;
    float f1;
    float f2;
    float f3;
    unsigned int flag;
};

struct Dst {
    char pad[0xa0];
    float d0;
    float d1;
    float d2;
    float d3;
    char pad2[3];
    unsigned char flag;
};

extern "C" void fn_27_46E48(struct Dst *dst, struct Src *src)
{
    unsigned int fl = src->flag;
    float d;
    float c;
    float b;
    float a;
    a = src->f0;
    b = src->f1;
    c = src->f2;
    d = src->f3;
    dst->d0 = a;
    dst->d1 = b;
    dst->d2 = c;
    dst->d3 = d;
    dst->flag = (unsigned char)(fl >> 31);
}
