#pragma force_active on

struct IntValue {
    int value;
};

struct Value {
    int value;
    char rest[0x5c];
};

extern "C" void fn_802DBD10(Value*, IntValue*);

extern "C" int fn_802DBCC8(void) {
    Value ret;
    IntValue value;
    value.value = 0;
    if (&ret != 0) {
        IntValue copy __attribute__((aligned(16))) = value;
        fn_802DBD10(&ret, &copy);
    }
    return ret.value;
}
