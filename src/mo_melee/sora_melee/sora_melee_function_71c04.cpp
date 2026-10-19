#pragma force_active on
struct Entry {
    void* object;
};

class Manager {
public:
    virtual void v0();
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
    virtual Entry* get(int);
    virtual void v21();
    virtual int find(int);
};

struct Context {
    unsigned char pad[0x20];
    Manager* manager;
};

extern "C" const float lbl_27_rodata_9B8[];
extern "C" void fn_27_7030C(void*, int, int, int, float);

extern "C" void fn_27_71C04(Context* self, int key, int a, int b) {
    int index = self->manager->find(key);
    Entry* entry = index < 0 ? 0 : self->manager->get(index);
    if (entry) {
        fn_27_7030C(entry->object, a, b, 1, lbl_27_rodata_9B8[0]);
    }
}
