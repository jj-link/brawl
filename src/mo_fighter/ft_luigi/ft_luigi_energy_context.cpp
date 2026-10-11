#include <mt/mt_vector.h>

class soModuleAccesser;
extern "C" void fn_27_1603F4(const Vec2f* vector, void* state, soModuleAccesser* accesser);
extern "C" void fn_27_160770(int kind, const Vec2f* vector, void* state, soModuleAccesser* accesser);
extern "C" void fn_27_16035C(void* context, int first, int second, int third);

extern "C" void fn_99_B154() {
}

extern "C" void fn_99_B158(void* object, const Vec2f* vector, soModuleAccesser* accesser) {
    fn_27_1603F4(vector, static_cast<u8*>(object) + 4, accesser);
}

extern "C" void fn_99_B168(void* object, int kind, const Vec2f* vector, soModuleAccesser* accesser) {
    fn_27_160770(kind, vector, static_cast<u8*>(object) + 4, accesser);
}

extern "C" void fn_99_B17C(void*, void* context, int first, int second, int third) {
    fn_27_16035C(context, first, second, third);
}

extern "C" int fn_99_B190() {
    return 8;
}

extern "C" s16* fn_99_B198(s16* destination, const s16* source) {
    *destination = *source;
    return destination;
}
