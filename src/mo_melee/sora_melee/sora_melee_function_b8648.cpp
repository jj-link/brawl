#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Fn27B8648Data {
    u32 prefix[19];
    u32 words[4];
    u8 byte;
};

struct Fn27B8648Out {
    u32 words[4];
    u8 byte;
};

extern "C" void fn_27_B8648(const Fn27B8648Data *src, Fn27B8648Out *dst)
{
    dst->words[0] = src->words[0];
    dst->words[1] = src->words[1];
    dst->words[2] = src->words[2];
    dst->words[3] = src->words[3];
    dst->byte = src->byte;
}
