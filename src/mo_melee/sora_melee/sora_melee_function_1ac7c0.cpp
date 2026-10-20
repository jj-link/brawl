#pragma force_active on
struct Value {
    unsigned int first;
    unsigned int second;
};

class Object {
public:
    virtual void unused();
    virtual Value& at(int index);
};

extern "C" void fn_27_1AC7C0(Object* self, const Value* value, int index) {
    self->at(index) = *value;
}
