#pragma force_active on
struct Object_vptr_1c_base {
    char pad0[0xc];
    int field_c;
    char pad1[0xc];
};
class Object_vptr_1c : public Object_vptr_1c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2(void*, int, int);
    char pad2[0xc8];
    unsigned short field_e8;
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual Object_vptr_1c* slot7();
    virtual void slot8(Object_vptr_1c*);
};
struct Context {
    char pad[0x20];
    Object_vptr_0** allocator;
    char list[0x18];
    unsigned short count;
};
extern "C" void fn_8015BFB4(void*, void*);
extern "C" Object_vptr_1c* fn_80163CE8(Context* self, int a, int b, int c) {
    Object_vptr_1c* obj = (*self->allocator)->slot7();
    if (obj == 0)
        return 0;
    if (obj->slot2(self, a, b) == 0) {
        (*self->allocator)->slot8(obj);
        return 0;
    }
    fn_8015BFB4(self->list, obj);
    self->count++;
    obj->field_c = 1;
    obj->field_e8 += c;
    return obj;
}