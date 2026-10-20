#pragma force_active on
struct Vector3 {
    float x, y, z;
};

class PositionModule {
public:
    virtual void unused();
    virtual const Vector3& getPosition() const;
};

struct Object {
    char padding[0x8c];
    PositionModule* position;
};

extern "C" float fn_27_17518(const Object* object) {
    return object->position->getPosition().y;
}
