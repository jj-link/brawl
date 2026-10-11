// Preserve the interface's virtual slot ordering without emitting a vtable.
class MarioParameterDispatch {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual void slot06(); virtual void slot07(); virtual void slot08();
    virtual void slot09(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13();
    virtual int dispatch();
    unsigned char beforeValue[4];
    int value;
};
extern "C" {
int fn_91_10268(MarioParameterDispatch* state) { return state->value; }
void fn_91_10270(MarioParameterDispatch* state, int value) { state->value = value; }
int fn_91_10278(MarioParameterDispatch* state) { return state->value; }
int fn_91_10280(MarioParameterDispatch* state) { return state->dispatch(); }
int fn_91_10290(MarioParameterDispatch*) { return -1; }
int fn_91_10298(MarioParameterDispatch* state) { return state->dispatch(); }
int fn_91_102A8(MarioParameterDispatch* state) { return state->dispatch(); }
int fn_91_102B8(MarioParameterDispatch* state) { return state->dispatch(); }
int fn_91_102C8(MarioParameterDispatch* state) { return state->dispatch(); }
}
