#pragma force_active on
struct Result {
    unsigned int unused;
    void* value;
};

class Object {
public:
    virtual void unused();
    virtual Result* get();
};

struct Context {
    unsigned int padding[10];
    Object* object;
};

extern "C" void fn_80134534(void*, int);

extern "C" void fn_27_29404(Context* __restrict context) {
    fn_80134534(context->object->get()->value, 4);
}
