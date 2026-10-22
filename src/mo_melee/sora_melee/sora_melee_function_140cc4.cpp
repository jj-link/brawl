#include <types.h>
#pragma force_active on

struct Target {
    virtual ~Target();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void methodA(void*, void*);
    virtual void methodB(void*);
    virtual void v24();
    virtual void methodC(void*);
};

struct Module {
    unsigned char pad[0x70];
    Target* target;
};

struct Parent {
    unsigned char pad[0xD8];
    Module* module;
};

struct Element {
    s32 value;
    void** inner_array;
    s32 inner_count;
};

struct ArrayDescriptor {
    Element* data;
    s32 count;
};

struct Self {
    unsigned char pad[0x2C];
    Parent* parent;
    ArrayDescriptor* arr_desc;
    s32 field_34;
    u8 field_38;
    u8 field_39;
};

extern "C" void fn_27_140CC4(Self* self, s32 arg1) {
    self->field_38 = 0;
    self->field_34 = arg1;
    if (self->field_39 != 1) {
        for (s32 i = 0; i < self->arr_desc->count; ++i) {
            if (arg1 == self->arr_desc->data[i].value) {
                for (s32 j = 0; j < self->arr_desc->data[i].inner_count; ++j) {
                    self->parent->module->target->methodA(self->arr_desc->data[i].inner_array[j], self->parent->module);
                    self->parent->module->target->methodC(self->arr_desc->data[i].inner_array[j]);
                    self->field_38 = 1;
                }
            } else {
                for (s32 j = 0; j < self->arr_desc->data[i].inner_count; ++j) {
                    self->parent->module->target->methodB(self->arr_desc->data[i].inner_array[j]);
                }
            }
        }
    }
}
