#pragma force_active on
extern "C" {

typedef struct {
    int unk0;
    unsigned int unk4;
    unsigned int flags;
} fn_40_30A14_Obj;

unsigned int fn_40_30A14(fn_40_30A14_Obj* obj)
{
    return (obj->flags >> 16) & 1;
}

}
