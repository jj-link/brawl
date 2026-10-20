#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int hi : 4;
    unsigned int rest : 28;
} Word8;

extern "C" void fn_66_A6C8(Word8 *p, unsigned int v)
{
    p->hi = v;
}
