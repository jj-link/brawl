#pragma force_active on

struct Obj {
    char pad[0x10];
    void* child;
};

extern "C" int fn_801C6B78(void* p);

extern "C" int fn_801C8B20(Obj* obj) {
    void* child = obj->child;
    if (child == 0) {
        return 0;
    }
    return fn_801C6B78(child);
}
