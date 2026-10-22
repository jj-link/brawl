#pragma force_active on
typedef struct {
    unsigned int w[10];
} Block40;

extern "C" {
void* fn_80191C94(void** src, void* dst)
{
    *(Block40*)dst = *(Block40*)(*src);
    return dst;
}
}
