#pragma force_active on
struct Query {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int get(unsigned long flags, void* obj);
};

struct Inner {
    char pad[0x64];
    Query* query;
};

struct Obj {
    char pad[0xD8];
    Inner* inner;
};

extern "C" void fn_27_17BE50(int self, void* arg);
extern "C" void fn_27_17C5DC(int self, void* arg);
extern "C" void fn_27_17CCE8(int self, void* arg);
extern "C" void fn_27_17D558(int self, void* arg);

extern "C" void fn_27_17B438(int self, Obj* arg) {
    Inner* inner = arg->inner;
    int state = inner->query->get(0x20000000, inner);
    switch (state) {
    case 0x2C:
        fn_27_17C5DC(self, arg);
        return;
    case 0x3D:
        fn_27_17BE50(self, arg);
        return;
    case 0x18:
        fn_27_17CCE8(self, arg);
        return;
    case 0xD:
        fn_27_17D558(self, arg);
        return;
    }
}
