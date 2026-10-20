#pragma force_active on
typedef unsigned int u32;

union Word
{
    u32 word;
    struct
    {
        unsigned int a : 4;
        unsigned int b : 4;
        unsigned int c : 24;
    } bits;
};

extern "C" void fn_40_1E654(void *object, u32 value)
{
    Word *field = (Word *)((char *)object + 8);
    field->bits.b = value;
}
