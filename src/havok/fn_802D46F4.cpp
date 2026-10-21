#pragma force_active on
struct Value { int value; };
extern "C" void fn_802D5284(char *, Value *);
extern "C" char lbl_80487588[];

extern "C" void fn_802D46F4(char *arg0) {
    Value value;
    value.value = 1;
    if (arg0 != 0) {
        Value copy = value;
        fn_802D5284(arg0, &copy);
        *(void **)(arg0 + 0x0) = lbl_80487588;
        *(void **)(arg0 + 0xC) = lbl_80487588 + 0x28;
    }
}
