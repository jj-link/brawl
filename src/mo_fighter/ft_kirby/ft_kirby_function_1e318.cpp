#include <types.h>
#pragma force_active on

struct KindStruct
{
    unsigned int kind[2];
    unsigned int flag : 4;
};

extern "C" void fn_96_1E318(KindStruct* obj, unsigned int arg2)
{
    obj->flag = arg2 & 0xF;
}
