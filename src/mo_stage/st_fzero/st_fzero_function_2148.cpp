#include <types.h>
#pragma force_active on

struct FZ2148 {
    unsigned char pad[0x184];
    unsigned char byte_184;
    int word_188;
    float flt_18c;
};

extern "C" void fn_61_2148(FZ2148 *obj, unsigned char b, int w, float f)
{
    obj->byte_184 = b;
    obj->word_188 = w;
    obj->flt_18c = f;
}
