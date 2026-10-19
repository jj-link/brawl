#pragma force_active on
struct StDXGreenStruct {
    unsigned char pad[0x6c];
    unsigned char field_6c;
};

extern "C" int fn_79_1B44(StDXGreenStruct *d)
{
    return (d->field_6c >> 3) & 1;
}
