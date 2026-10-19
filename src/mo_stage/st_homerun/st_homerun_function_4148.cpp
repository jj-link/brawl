#pragma force_active on
struct S_4148 {
    unsigned char pad[0x184];
    unsigned char byte_184;
    int word_188;
    float float_18c;
};

extern "C" void fn_88_4148(S_4148* p, unsigned char b, int w, float f)
{
    p->byte_184 = b;
    p->word_188 = w;
    p->float_18c = f;
}
