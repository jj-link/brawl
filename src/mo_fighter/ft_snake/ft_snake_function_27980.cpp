#pragma force_active on
struct Vector3 {
    float x;
    float y;
    float z;
};

struct SnakeState {
    unsigned char padding[0x20];
    Vector3 position;
};

extern "C" void fn_122_27980(SnakeState* object, const Vector3* value) {
    object->position.x = value->x;
    object->position.y = value->y;
    object->position.z = value->z;
}
