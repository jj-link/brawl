#pragma force_active on
typedef int s32;

extern s32 fn_803C42D8(void **);
extern void **fn_803C4338(s32);
extern s32 fn_803C9ED8(s32, s32);

s32 fn_803C7F98(s32 arg0, s32 arg1)
{
    s32 result;
    void **entry;
    void *data;
    s32 id;

    entry = fn_803C4338(arg0);
    result = -1;
    if (entry != 0) {
        data = *entry;
        if (data != 0) {
            if (((s32 *)data)[2] == 0) {
                id = fn_803C42D8(entry);
                if (id != -1) {
                    result = fn_803C9ED8(id, arg1);
                }
            } else {
                result = 0;
            }
        }
    }
    return result;
}
