#pragma force_active on
#pragma use_lmw_stmw on
class Class_8027D01C {
public:
    void* data;
    unsigned int size;
    int a, b;
};
struct Array {
    void* data;
    int size;
    unsigned int capacity;
};
struct Descriptor {
    char pad[0x20];
    int start;
    int end;
    char tail[8];
};
struct Header {
    char pad[0x14];
    int count;
};
class Object_vptr_0 {
public:
    virtual void slot0(int);
    virtual void slot1();
    virtual void slot2();
    virtual int slot3(int);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    unsigned short size;
    short refs;
};
class Class_80488EE0 {
public:
    virtual void fn_8032FA40();
    virtual void fn_80080A64();
    virtual void fn_8032FCB4();
    virtual void fn_80330928();
    virtual void fn_8033259C();
    virtual void fn_803315A4();
    virtual void fn_80330698();
    virtual void fn_8032FF60();
    virtual void fn_803309D0();
    virtual void fn_8032FCAC();
    virtual void fn_8032FD74();
    virtual void fn_80331408();
    virtual int fn_80331494(int, int);
    char pad[8];
    Header* header;
    Descriptor* desc;
    char** bases;
    char pad18[0x4c];
    Array* result;
};
class SoHeapAllocator {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual Array* alloc(int, int);
};
struct Callback {
    void* vtable;
    Array* result;
    Class_8027D01C* map;
};
extern SoHeapAllocator* lbl_805A0EB8;
extern char lbl_80488E80[];
extern "C" void __ct__14Class_8027D01CFv(Class_8027D01C*);
extern "C" void __dt__14Class_8027D01CFv(Class_8027D01C*, int);
extern "C" Object_vptr_0* fn_80330274();
extern "C" void fn_8027D0B8(Class_8027D01C*, void*, int);
extern "C" void fn_8027CD94(Array*, int, int);
extern "C" int fn_80331560(Class_80488EE0*);
extern "C" void* fn_803314B8(Class_80488EE0*);
extern "C" void fn_8033344C(void*, int, Callback*);
extern "C" Array* fn_80330698(Class_80488EE0* self) {
    if (!self->result) {
        Object_vptr_0* object = fn_80330274();
        struct Locals { Class_8027D01C map; Callback callback; Class_8027D01C other; } locals;
        __ct__14Class_8027D01CFv(&locals.map);
        int* entry;
        char* base;
        int i;
        Descriptor* d;
        for (i = 0; i < self->header->count; ++i) {
            base = self->bases[i];
            if (base) {
                d = &self->desc[i];
                entry = (int*)(base + d->start);
                for (int j = 0; j < (d->end - d->start) / 4; entry += 3, j += 3) {
                    int offset = entry[0];
                    if (offset != -1) {
                        fn_8027D0B8(&locals.map, base + offset, object->slot3(self->fn_80331494(entry[1], entry[2])));
                    }
                }
            }
        }
        Array* result = lbl_805A0EB8->alloc(12, 0x15);
        if (result) {
            result->data = 0;
            result->size = 0;
            result->capacity = 0x80000000;
        }
        self->result = result;
        locals.callback.vtable = lbl_80488E80;
        locals.callback.result = result;
        locals.callback.map = &locals.map;
        __ct__14Class_8027D01CFv(&locals.other);
        int count = locals.map.size & 0x7fffffff;
        int capacity = self->result->capacity & 0x3fffffff;
        if (capacity < count) {
            int doubled = capacity * 2;
            if (count < doubled) count = doubled;
            fn_8027CD94(self->result, count, 8);
        }
        int value = object->slot3(fn_80331560(self));
        fn_8033344C(fn_803314B8(self), value, &locals.callback);
        if (object->size != 0) {
            if (--object->refs == 0 && object != 0) object->slot0(1);
        }
        __dt__14Class_8027D01CFv(&locals.other, -1);
        __dt__14Class_8027D01CFv(&locals.map, -1);
    }
    return self->result;
}