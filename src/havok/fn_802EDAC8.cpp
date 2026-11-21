#pragma force_active on
#pragma opt_common_subs off

class Context;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void* slot3();

    char pad[4];
    Context* context;
    char pad2[0x18];
    void* value;
};

struct Array {
    Object_vptr_0** data;
    int size;
    unsigned int capacity;
};

class Context {
public:
    char pad[0x78];
    int pending;
    int count;
    int count2;
    signed char flag;
    char pad2[0x47];
    Array array;
};

struct Message {
    signed char type;
    char pad[3];
    Object_vptr_0* object;
};

extern "C" void fn_802EFF2C(Context*, Message*);
extern "C" void fn_802F064C(Object_vptr_0*);
extern "C" void fn_8027CE3C(Array*, int);
extern "C" void fn_802F827C(Context*, Object_vptr_0*);
extern "C" void fn_802F3E78(Context*, Object_vptr_0*);
extern "C" void fn_802E8584(Object_vptr_0*);
extern "C" void fn_802EFE70(Context*);

extern "C" Object_vptr_0* fn_802EDAC8(Context* self, Object_vptr_0* object) {
    if (((const int*)self)[0x7C / 4] + self->count2 != 0) {
        Message msg;
        msg.object = object;
        msg.type = 13;
        fn_802EFF2C(self, &msg);
        return 0;
    } else {
        self->count++;
        if (!object->value) {
            object->value = object->slot3();
        }

        object->context = self;
        fn_802F064C(object);

        if (self->array.size == (int)(self->array.capacity & 0x3fffffff)) {
            fn_8027CE3C(&self->array, 4);
        }

        self->array.data[self->array.size++] = object;
        fn_802F827C(self, object);
        fn_802F3E78(self, object);
        fn_802E8584(object);

        self->count--;
        if (self->count == 0 && self->pending != 0 && self->flag == 0) {
            fn_802EFE70(self);
        }

        return object;
    }
}
