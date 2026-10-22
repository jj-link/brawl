#pragma force_active on

extern "C" unsigned int fn_122_DA20(void*, void*);
extern "C" void fn_27_6678(void*, int, int, void*);

struct Result {
    void* a;
    void* b;
    void* c;
};

struct ObjectA {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Result slot6();
};

struct ObjectB {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot5(int id, void* self);
};

extern "C" void fn_122_DB6C(void* self, int arg1, int arg2, void* arg3) {
    if (arg1 == 0xD && arg2 == 1) {
        ObjectA* obj = *reinterpret_cast<ObjectA**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(arg3) + 0xD8)) + 0xC);
        const Result& sp8 = obj->slot6();
        if (fn_122_DA20(self, const_cast<Result*>(&sp8)) == 1) {
            void* owner = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x60);
            ObjectB* obj2 = *reinterpret_cast<ObjectB**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(owner) + 0xD8)) + 0x70);
            obj2->slot5(0x12E, owner);
        }
    }
    fn_27_6678(self, arg1, arg2, arg3);
}
