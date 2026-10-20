#pragma force_active on
struct Value {
    unsigned int x, y, z;
};

class Array {
public:
    virtual ~Array();
    virtual const Value& at(int index) const = 0;
};

struct Object {
    unsigned int unknown;
    Array* array;
};

extern "C" void fn_27_71948(Value* result, const Object* object, int index) {
    if (object->array == 0) {
        result->x = 0;
        result->y = 0;
        result->z = 0;
    } else {
        const Value& value = object->array->at(index);
        unsigned int z = value.z;
        unsigned int y = value.y;
        unsigned int x = value.x;
        result->x = x;
        result->y = y;
        result->z = z;
    }
}
