#include <types.h>
#pragma force_active on

class Vec2f {
public:
    float m_x;
    float m_y;
};

struct soModuleAccesser {
    char field_4[0x100];
};

extern "C" {
void fn_27_1603F4(const Vec2f* vector, void* state, soModuleAccesser* accesser);
void fn_27_160770(int kind, const Vec2f* vector, void* state, soModuleAccesser* accesser);
}

extern "C" void fn_97_DEA8(void* object, int kind, const Vec2f* vector, soModuleAccesser* accesser) {
    fn_27_160770(kind, vector, (u8*)object + 4, accesser);
}
