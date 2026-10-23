#pragma force_active on
struct Value { int value; };
extern "C" void fn_802DA52C(int, Value*);

extern "C" void fn_802DA49C(int arg0) {
    Value value;
    value.value = 1;
    if (arg0 != 0) {
        Value copy = value;
        fn_802DA52C(arg0, &copy);
    }
}
