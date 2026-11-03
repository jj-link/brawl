#include <types.h>
#pragma force_active on
class Class_80487A10 {
public:
    virtual void fn_802DA584();
    virtual void fn_80080A64();
    virtual void fn_802DAB00();
    virtual int fn_802DA618();
    virtual void fn_802DA684(s8*, int*);
    virtual void fn_802DE25C();
    virtual void fn_802DE240();
    virtual void fn_802DA6BC();
    virtual void fn_802DA620();
    virtual void fn_802DAAF8();
    char pad[0x14];
    Class_80487A10* ptr;
    u16 a;
    u16 b;
};
struct Data { char pad[8]; int value; };
class Class_80487B18 {
public:
    virtual void fn_802D8148();
    virtual void fn_80080A64();
    virtual void fn_802DE230();
    virtual void fn_802DE238();
    virtual void fn_802DDAE4();
    virtual int fn_802DDAF4();
    virtual void fn_802DE240();
    virtual void fn_802D95E0();
    virtual void fn_802DDAD4();
    virtual void fn_802DE058();
    char pad[8];
    Class_80487A10* object;
    char pad2[0x28];
    Data* data;
};
struct Context { char pad[0x78]; int pending; int busy; char pad2[4]; u8 active; };
struct Message { s8 type; Class_80487B18* object; };
extern "C" void fn_802EFF2C(Context*, Message*);
extern "C" void fn_802DE8BC(Class_80487B18*);
extern "C" int fn_802F8F00(Context*, Class_80487B18*, int);
extern "C" void fn_802ED630(Context*, Data*);
extern "C" void fn_802EFE70(Context*);
extern "C" int fn_802ED3EC(Context* self, Class_80487B18* obj) {
    if (self->busy) {
        Message msg;
        msg.object = obj;
        msg.type = 8;
        fn_802EFF2C(self, &msg);
        return 0;
    }
    if (obj->object->fn_802DA618() == 12) {
        Class_80487A10* shape = obj->object;
        if (shape->a == 0) {
            s8 flag = 1;
            int out[2];
            shape->ptr->fn_802DA684(&flag, out);
            shape->a = out[0];
            shape->b = out[1];
        }
    }
    self->active = 1;
    fn_802DE8BC(obj);
    int result = fn_802F8F00(self, obj, 1);
    if (obj->fn_802DDAF4() == 1) {
        if (obj->data->value == 0) {
            fn_802ED630(self, obj->data);
        }
        obj->object->fn_802DAAF8();
    }
    self->active = 0;
    if (self->busy == 0 && self->pending != 0 && self->active == 0) {
        fn_802EFE70(self);
    }
    return result;
}