#include <types.h>
#pragma force_active on

extern "C" {
float fn_80194140(void*, float);
float fn_8019426C(void*, float);
float fn_801943DC(void*, float);
extern const float lbl_805A31F0;
}

union Word {
    float f;
    int i;
};

extern "C" const Word* fn_80194FF8(float* out, const char* base, const Word* p, float frame) {
    unsigned int flags;
    float x, y, z;
    const Word* q;

    switch ((flags = *(const unsigned int*)(base + 4)) & 0xC0000000) {
    case 0:
        x = (p++)->f;
        y = (p++)->f;
        z = (p++)->f;
        break;

    case 0x40000000:
        q = p++;
        x = flags & 0x80000 ? q->f : fn_801943DC((void*)(q->i + (int)base), frame);
        q = p++;
        y = flags & 0x100000 ? q->f : fn_801943DC((void*)(q->i + (int)base), frame);
        q = p++;
        z = flags & 0x200000 ? q->f : fn_801943DC((void*)(q->i + (int)base), frame);
        break;

    case 0x80000000:
        q = p++;
        x = flags & 0x80000 ? q->f : fn_8019426C((void*)(q->i + (int)base), frame);
        q = p++;
        y = flags & 0x100000 ? q->f : fn_8019426C((void*)(q->i + (int)base), frame);
        q = p++;
        z = flags & 0x200000 ? q->f : fn_8019426C((void*)(q->i + (int)base), frame);
        break;

    case 0xC0000000:
        q = p++;
        x = flags & 0x80000 ? q->f : fn_80194140((void*)(q->i + (int)base), frame);
        q = p++;
        y = flags & 0x100000 ? q->f : fn_80194140((void*)(q->i + (int)base), frame);
        q = p++;
        z = flags & 0x200000 ? q->f : fn_80194140((void*)(q->i + (int)base), frame);
        break;

    default:
        x = lbl_805A31F0;
        y = x;
        z = x;
        break;
    }

    out[0] = x;
    out[1] = y;
    out[2] = z;
    return p;
}
