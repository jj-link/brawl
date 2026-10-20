#pragma force_active on
struct Result {
    char padding[0x4C];
    float x;
    float y;
    float z;
};

struct Provider {
    virtual void unused();
    virtual Result* get();
};

struct Context {
    char padding[8];
    Provider* provider;
};

extern "C" void fn_27_37880(Context* self, float x, float z) {
    Result* result = self->provider->get();
    result->x = x;
    result->z = z;
}
