#pragma force_active on
struct Obj {
    int field0;
    unsigned char field4;
};

struct MyClass {
    Obj* target;
};

extern "C" void fn_802D6AC8(MyClass* self, Obj* arg) {
    arg->field0 = 3;
    arg->field4 = 1;
}
