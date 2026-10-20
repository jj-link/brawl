#pragma force_active on
extern "C" void reset__18gfGameFrameCounterFv(void*);
extern "C" void start__18gfGameFrameCounterFv(void*);

class Module {
public:
    virtual void invoke();
};

struct Accesser {
    unsigned char padding[0x90];
    Module* module;
};

struct Object {
    unsigned char padding[0xD8];
    Accesser* accesser;
};

struct State {
    unsigned int unknown;
    unsigned int value;
    unsigned char counter[1];
};

extern "C" void fn_27_A90F8(State* self, Object* object, unsigned int value)
{
    object->accesser->module->invoke();
    self->value = value;
    reset__18gfGameFrameCounterFv(self->counter);
    start__18gfGameFrameCounterFv(self->counter);
}
