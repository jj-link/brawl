#include <types.h>

struct PeachVector2 {
    f32 x;
    f32 y;
};

extern "C" PeachVector2* fn_103_C174(PeachVector2* destination, const PeachVector2* source) {
    destination->x = source->x;
    destination->y = source->y;
    return destination;
}
