#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int getCount(int);
    virtual void setValue(int, int);
};

struct Class_90D8_base {
    char pad[0x8];
};

class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual float fn_27_7B0B0();
};

struct FunctionData {
    char pad[0x64];
    Object_vptr_0* object;
    char pad2[0x54];
    Class_90D8* value;
};

struct FunctionOwner {
    char pad[0xD8];
    FunctionData* data;
};

struct FunctionSelf {
    char pad[0x60];
    FunctionOwner* owner;
};

extern "C" void fn_27_1DACB8(void*);

extern "C" void fn_27_36D630(FunctionSelf* self) {
    int count = self->owner->data->object->getCount(0x10000005);
    if (count > 0) {
        float rate = self->owner->data->value->fn_27_7B0B0();
        float value = (float)count;
        value *= rate;
        self->owner->data->object->setValue((int)value, 0x10000005);
    }
    fn_27_1DACB8(self);
}
