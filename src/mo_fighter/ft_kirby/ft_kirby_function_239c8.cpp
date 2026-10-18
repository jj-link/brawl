#pragma force_active on
typedef unsigned char u8;

typedef struct {
    char pad[0xa4];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 rest : 6;
} S;

extern "C" {
bool fn_96_239C8(void* p)
{
    return ((S*)p)->f1;
}
}
