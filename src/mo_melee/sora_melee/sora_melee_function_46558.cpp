#pragma force_active on
typedef struct {
    char pad[0x64];
    short field;
} FnObj;

extern "C" int fn_27_46558(FnObj* p)
{
    return !(p->field < 0);
}
