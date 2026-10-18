#pragma force_active on
typedef unsigned int u32;

struct F184 {
    char pad[0x184];
    unsigned char b184;
    u32 i188;
    float f18c;
};

extern "C" {
void fn_43_914(F184* p, unsigned char b, u32 i, float f) {
    p->b184 = b;
    p->i188 = i;
    p->f18c = f;
}
}
