#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    unsigned int flags;
} FlagObj;

extern "C" {
unsigned int fn_40_1E694(FlagObj* obj) {
    return (obj->flags >> 19) & 1;
}
}
