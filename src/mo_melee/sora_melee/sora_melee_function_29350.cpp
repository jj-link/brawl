#pragma force_active on
struct Result {
    unsigned int unknown;
    void* object;
};

class Module {
public:
    virtual ~Module();
    virtual Result* get() = 0;
};

struct Context {
    unsigned char padding[0x28];
    Module* module;
};

extern "C" void fn_80134534(void*, int);

extern "C" void fn_27_29350(Context* __restrict self) {
    Module* module = self->module;
    Result* result = module->get();
    fn_80134534(result->object, 0);
}
