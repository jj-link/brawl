#pragma force_active on
struct Value { int value; };
extern "C" void fn_802D5284(int, Value*);

extern "C" void fn_802D51F4(int arg0) {
    Value value;
    value.value = 1;
    if (arg0 != 0) {
        Value copy = value;
        fn_802D5284(arg0, &copy);
    }
}
