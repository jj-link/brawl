#pragma force_active on
typedef struct StageFlags
{
    int pad[2];
    unsigned int flags;
} StageFlags;

extern "C" {
int fn_48_B038(StageFlags *obj)
{
    return (int)((obj->flags << 7) & 0xFF000000) >> 25;
}
}
