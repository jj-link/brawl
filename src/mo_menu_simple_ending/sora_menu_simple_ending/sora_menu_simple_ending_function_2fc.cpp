#pragma force_active on
extern "C" void fn_800B8EDC(void*, void*);
extern "C" void fn_800B8A0C(void*, int);
extern "C" void fn_8018E808(void*);
extern "C" void exit__6gfTaskFv(void*);

struct MenuObjectBase {
    char pad[0x5C];
};

class MenuObject : public MenuObjectBase {
public:
    virtual void destroy(int);
};

extern "C" void fn_19_2FC(void* self) {
    char* s = (char*)self;
    fn_800B8EDC(*(void**)(s + 0x50), *(void**)(s + 0x4C));
    fn_800B8A0C(*(void**)(s + 0x50), 1);

    void* task = *(void**)(s + 0x48);
    *(void**)(s + 0x50) = 0;
    exit__6gfTaskFv(task);

    MenuObject* obj = *(MenuObject**)(s + 0x4C);
    *(void**)(s + 0x48) = 0;
    if (obj != 0) {
        obj->destroy(1);
    }

    *(void**)(s + 0x4C) = 0;
    fn_8018E808(s + 0x40);
    fn_8018E808(s + 0x44);
}
