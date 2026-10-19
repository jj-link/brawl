#pragma force_active on
typedef struct StDxGreensObject {
    int unk00;
    int unk04;
    int flags08;
} StDxGreensObject;

extern "C" int fn_79_4580(StDxGreensObject *obj)
{
    return obj->flags08 >> 26;
}
