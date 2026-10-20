#pragma force_active on
struct Fields
{
    unsigned int field0;
    unsigned int field1;
    unsigned int field2;
};

extern "C" void fn_27_2370C(Fields* dst, const Fields* src)
{
    const Fields* fields = reinterpret_cast<const Fields*>(
        reinterpret_cast<const unsigned char*>(src) + 0x6C);

    dst->field0 = fields->field0;
    dst->field1 = fields->field1;
    dst->field2 = fields->field2;
}
