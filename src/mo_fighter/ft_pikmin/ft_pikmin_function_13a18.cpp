#pragma force_active on
typedef unsigned int u32;

struct PikminField
{
    u32 prefix[2];
    unsigned int reserved : 5;
    unsigned int value : 5;
};

extern "C" void fn_113_13A18(void* self, u32 value)
{
    reinterpret_cast<PikminField*>(self)->value = value;
}
