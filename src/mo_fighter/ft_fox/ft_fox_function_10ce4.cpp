#pragma force_active on
struct S {
    unsigned int field_0;
    unsigned int field_4;
    unsigned int field_8;
    unsigned int field_c;
    unsigned int field_10;
};

extern "C" void fn_97_10CE4(S *object, unsigned int arg1)
{
    object->field_10 = arg1;
    object->field_c = arg1;
    object->field_8 = arg1;
}
