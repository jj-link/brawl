#include <mo_fighter/ft_lucas/ft_lucas_speed_pair.h>

extern "C" void* fn_114_C4D4(void* object, const LucasSpeedPair* speed, float third) {
    float* components = static_cast<float*>(object);
    components[0] = speed->x;
    components[1] = speed->y;
    components[2] = third;
    return object;
}
