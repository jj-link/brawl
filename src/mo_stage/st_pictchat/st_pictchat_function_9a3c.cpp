#pragma force_active on
extern "C" void fn_73_9A3C(void *object, int value1, int value2)
{
    struct Object
    {
        char padding[0x51C];
        int field1;
        char gap[4];
        int field2;
    };

    Object *p = (Object *)object;
    p->field1 = value1;
    p->field2 = value2;
}
