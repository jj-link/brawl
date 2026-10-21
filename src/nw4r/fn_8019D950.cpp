#pragma force_active on

class Inner {
public:
    virtual void f0();
    virtual void method1(int, int, void*);
};

struct Obj {
    char pad[4];
    Inner* field_4;
};

extern "C" void* fn_8019D950(void* arg0) {
    Obj* obj = (Obj*)arg0;
    Inner* inner = obj->field_4;
    if (inner != 0) {
        inner->method1(0x10001, 0, arg0);
    }
    return inner;
}
