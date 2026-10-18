#pragma force_active on
struct Vec2f {
    float x, y, z;
};

struct Accesser {
    int kind;
    Vec2f vec;
};

extern "C" void fn_27_1603F4(const Vec2f* vector, void* state, Accesser* accesser);

extern "C" void fn_97_DE98(const Vec2f* vector, const Vec2f* object, Accesser* accesser) {
    fn_27_1603F4(object, (void*)((char*)vector + 4), accesser);
}
