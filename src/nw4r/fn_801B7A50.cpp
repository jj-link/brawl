#include <types.h>
#pragma force_active on
struct Data { char padding[0x1c]; float start; float end; int duration; int elapsed; };
extern "C" float fn_801B7A50(const Data* p) {
    if (p->elapsed >= p->duration) return p->end;
    return p->start + ((float)p->elapsed * (p->end - p->start)) / (float)p->duration;
}