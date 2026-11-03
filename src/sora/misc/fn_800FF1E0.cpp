#pragma force_active on
class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AB290();
    virtual void fn_801B2EEC(void*, void*);
    virtual void fn_801B3050();
    virtual void fn_801B3248(void*);
    char pad[0xE0];
    void* fieldE4;
};
struct Resource { char pad[0x10]; void* field10; };
struct Self {
    Class_8042B6D0* object;
    void* data;
    char pad[0x5c];
    Resource* resource;
    char pad68[0x88];
    void* fieldF0;
    void* fieldF4;
    void* fieldF8;
};
extern "C" int fn_800B5854(void*, int, int, int, int);
extern "C" void fn_800FECD4(void*, int, float);
extern float lbl_805A2748;
extern "C" void fn_800FF1E0(Self* self) {
    void* data = self->data;
    self->object->fn_801B3248(self->fieldF0);
    self->object->fn_801B3248(self->fieldF4);
    self->object->fn_801B3248(self->fieldF8);
    Class_8042B6D0* obj = self->object;
    obj->fn_801B2EEC(obj->fieldE4, self->fieldF0);
    fn_800B5854(data, 0, 1, 0, 0);
    self->object->fn_801B3248(self->resource->field10);
    fn_800FECD4(self, 0, lbl_805A2748);
}