#pragma force_active on
typedef struct {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int flags;
} StCrollWork;

#ifdef __cplusplus
extern "C"
#endif
unsigned int fn_90_29B0(StCrollWork *work, unsigned int mask)
{
    unsigned int x = work->flags & mask;
    return ((0u - x) | x) >> 31;
}
