#pragma force_active on
struct StdxGrass {
    unsigned int field0;
    unsigned int field4;
    unsigned int field8;
};

extern "C" unsigned int fn_79_5868(StdxGrass *obj)
{
    return (obj->field8 >> 13) & 1;
}
