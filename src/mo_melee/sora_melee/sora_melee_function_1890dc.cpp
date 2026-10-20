#pragma force_active on
struct Object;

struct StatusModule {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void changeStatus(int, Object*);
};

struct Modules {
    char padding[0x70];
    StatusModule* status;
};

struct Object {
    char padding[0xD8];
    Modules* modules;
};

extern "C" int fn_27_1890DC(void*, Object* object) {
    object->modules->status->changeStatus(0xED, object);
    return 1;
}
