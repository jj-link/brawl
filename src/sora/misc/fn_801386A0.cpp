#pragma force_active on
struct Class_8045DD44_base { char pad[0x28]; };
class Class_8045DD44 : public Class_8045DD44_base {
public:
    virtual void fn_801385F0();
    virtual void fn_80138630();
    virtual void fn_80138668();
    virtual void fn_801386A0();
    virtual void fn_80138738(int);
    virtual void fn_80138CB4();
    virtual void fn_80139220();
};

extern "C" void fn_801386A0(Class_8045DD44* self, int arg) {
    if (arg != 0) {
        self->fn_80138738(arg);
        self->fn_80139220();
        self->fn_80138CB4();
    }
}