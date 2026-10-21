#pragma force_active on
struct Owner {
    virtual void unused();
    virtual char* get();
};
struct Module {
    virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3();
    virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7();
    virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11();
    virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15();
    virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
    virtual void u20(); virtual void u21();
    virtual void call();
};
struct Modules { char reserved[0x0C]; Module* module; };
struct Data { char reserved[0xD8]; Modules* modules; };
struct Accessor { char reserved[0x44]; Data* data; };
struct Context { char reserved[0x48]; Owner* owner; };
extern "C" Accessor* fn_27_6F30C(void*);
extern "C" void fn_27_6C384(Context* __restrict self) {
    char* r = self->owner->get();
    fn_27_6F30C(r + 0x1C)->data->modules->module->call();
}
