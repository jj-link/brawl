#pragma force_active on
struct ValueObject {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual int getValue(int);
};

struct Accesser {
    unsigned char padding[0xD8];
    struct Modules {
        unsigned char padding[0x64];
        void* module;
    }* modules;
};

extern "C" void* fn_41_473DC(void*, int);
extern "C" void fn_41_47470(void*, void*, void*);
extern "C" void fn_41_47544(unsigned char*, void*);
extern "C" void fn_41_47A2C(void*, void*, int);
extern "C" void fn_41_47D8C(void*, unsigned char, void*, void*, void*);

extern "C" int fn_41_69EB4(void* self, Accesser* accesser) {
    ValueObject* value = static_cast<ValueObject*>(accesser->modules->module);
    int key = value->getValue(0x10000007);
    void* p = fn_41_473DC(accesser, key);

    unsigned char flag;
    unsigned int buffer[3];
    fn_41_47470(buffer, p, accesser);
    flag = 0;
    fn_41_47544(&flag, p);
    fn_41_47A2C(p, accesser, 1);
    fn_41_47D8C(buffer, flag, self, p, accesser);
    return 0;
}
