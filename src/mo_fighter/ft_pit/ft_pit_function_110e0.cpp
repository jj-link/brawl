#pragma force_active on
typedef struct FtPitObj
{
    char pad[0xa4];
    unsigned char f0 : 1;
    unsigned char f1 : 1;
    unsigned char f2 : 1;
    unsigned char f3 : 1;
    unsigned char f4 : 1;
    unsigned char f5 : 1;
    unsigned char f6 : 1;
    unsigned char f7 : 1;
} FtPitObj;

extern "C" int fn_112_110E0(FtPitObj *obj)
{
    return obj->f1 != 0;
}
