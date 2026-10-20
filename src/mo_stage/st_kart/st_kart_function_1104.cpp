#pragma force_active on
typedef struct {
    char pad[0x184];
    unsigned char f184;
    int f188;
    float f18c;
} StKartObj;

extern "C" void fn_49_1104(StKartObj *obj, unsigned char v, int i, float f)
{
    obj->f184 = v;
    obj->f188 = i;
    obj->f18c = f;
}
