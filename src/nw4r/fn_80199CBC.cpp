#pragma force_active on

class Object {
public:
    virtual char* f0();
    virtual char* f1();
    virtual char* f2();
    virtual char* f3();
};

extern "C" char* fn_80199CBC(Object* self) {
    return self->f3() + 4;
}
