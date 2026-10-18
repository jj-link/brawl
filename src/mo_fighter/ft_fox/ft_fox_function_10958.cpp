#pragma force_active on
typedef struct FtObj {
    unsigned char pad[0xa4];
    unsigned char a : 1;
    unsigned char flag : 1;
    unsigned char b : 6;
} FtObj;

extern "C" {
bool fn_97_10958(FtObj* p)
{
    return p->flag;
}
}
