#pragma force_active on
struct State {
    unsigned char pad[5];
    unsigned char enabledFlag : 1;
    unsigned char : 7;
    unsigned char value;

    bool enabled() const { return enabledFlag; }
};

extern "C" void fn_115_1828C(State*, void*);

extern "C" int fn_115_1823C(void*, State* state, void* arg) {
    if (state->enabled() == true && state->value == 0) {
        fn_115_1828C(state, arg);
    }
    return 1;
}
