#pragma force_active on
typedef struct FtKoopaObj
{
    char pad[0xa4];
    unsigned char a : 1;
    unsigned char f : 1;
    unsigned char b : 6;
} FtKoopaObj;

extern "C" bool fn_102_1BCB0(FtKoopaObj *self)
{
    return self->f;
}
