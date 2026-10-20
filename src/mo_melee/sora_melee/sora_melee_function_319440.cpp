#pragma force_active on
typedef unsigned int u32;

struct Value {
    u32 first;
    u32 second;
};

class Object {
public:
    virtual ~Object();
    virtual Value* at(int index);
};

extern "C" void fn_27_319440(Object* object, const Value* value, int index) {
    *object->at(index) = *value;
}
