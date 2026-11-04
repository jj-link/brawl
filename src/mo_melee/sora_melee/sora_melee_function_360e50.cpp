#include <mt/mt_prng.h>
#pragma force_active on

extern "C" {
float* fn_27_3610E8();
extern char lbl_27_data_19FC8[];
extern float lbl_27_data_90688;
extern const float lbl_27_rodata_7A78[];
}

class Class_19FD0 {
public:
    virtual void fn_27_DCA5C();
    virtual float& fn_27_DC3F0(int);
    virtual void fn_27_DC400();
    virtual int fn_27_D32CC();
    virtual void fn_27_86AD0();
    virtual void fn_27_D320C();
    virtual void fn_27_DC504();
    virtual void fn_27_DC6B4();
    virtual void fn_27_DCA14();
    virtual void fn_27_DC410();
    virtual void fn_27_DC5C0(const float&);
};

class Class_7618 {
public:
    virtual void fn_27_66114();
    virtual void fn_27_66154();
    virtual void fn_27_661B4();
    virtual void fn_27_661B8();
    virtual int fn_27_661C8(int);
    virtual void fn_27_661D4(int, int);
};

struct Modules {
    char pad[0x64];
    Class_7618* work;
};

struct Owner {
    char pad[0xd8];
    Modules* modules;
};

struct Array {
    void* vtable;
    void* calc;
    unsigned int flags;
    float values[5];
};

inline int selectValue(Array& array, float target, float accumulated) {
    for (int i = 0; i < reinterpret_cast<Class_19FD0*>(&array)->fn_27_D32CC(); ++i) {
        accumulated += reinterpret_cast<Class_19FD0*>(&array)->fn_27_DC3F0(i);
        if (target <= accumulated)
            return i;
    }
    return randi(5);
}

extern "C" int fn_27_360E50(Owner* self) {
    const float* const constants = lbl_27_rodata_7A78;
    float* params = fn_27_3610E8();
    Array array;
    array.vtable = lbl_27_data_19FC8;
    array.calc = lbl_27_data_19FC8 + 0x48;
    array.flags &= 0x7ffff;

    float sum = constants[0];
    float* cursor = params + 2;
    for (int i = 0; i < 5; ++i, ++params, ++cursor) {
        if (i == self->modules->work->fn_27_661C8(0x10000040)) {
            reinterpret_cast<Class_19FD0*>(&array)->fn_27_DC5C0(lbl_27_data_90688);
        } else if (i == self->modules->work->fn_27_661C8(0x10000041)) {
            float value = params[2] * constants[2];
            reinterpret_cast<Class_19FD0*>(&array)->fn_27_DC5C0(value);
            sum += params[2] * constants[2];
        } else {
            reinterpret_cast<Class_19FD0*>(&array)->fn_27_DC5C0(*cursor);
            sum += params[2];
        }
    }

    int selected;
    if (sum <= constants[0]) {
        selected = self->modules->work->fn_27_661C8(0x10000040);
    } else if (sum <= constants[0]) {
        selected = -1;
    } else {
        float target = sum * randf();
        if (constants[0] == target)
            target += constants[3];
        selected = selectValue(array, target, constants[0]);
    }

    Class_7618* work = self->modules->work;
    work->fn_27_661D4(work->fn_27_661C8(0x10000040), 0x10000041);
    self->modules->work->fn_27_661D4(selected, 0x10000040);
    return selected;
}
