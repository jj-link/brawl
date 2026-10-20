#pragma force_active on
class Object {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void* get(int);

    char padding04[0x18];
    void* field1c;
    char padding20[0xC];
    int field2c;
};

extern "C" void fn_27_89E34(void*, void*, void*);

extern "C" void fn_27_1DC2B8(Object* self, int kind, void* value) {
    switch (kind) {
    case 0:
        if (self->field2c != -1) {
            void* result = self->get(self->field2c);
            fn_27_89E34(result, value, self->field1c);
        }
        break;
    }
}
