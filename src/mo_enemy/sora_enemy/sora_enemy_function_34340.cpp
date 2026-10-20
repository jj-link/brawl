#pragma force_active on
typedef unsigned int u32;

struct Value {
    u32 first;
    u32 second;
};

class Accesser {
public:
    virtual void unused();
    virtual Value* get(u32 index);
};

extern "C" void fn_41_34340(Accesser* self, const Value* value, u32 index) {
    Value* destination = self->get(index);
    destination->first = value->first;
    destination->second = value->second;
}
