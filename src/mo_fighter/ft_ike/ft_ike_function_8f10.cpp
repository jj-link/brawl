#pragma force_active on
typedef unsigned char u8;

struct Root {
    u8 pad[0x60];
    void* field;
};

struct First {
    u8 pad[0xD8];
    void* field;
};

struct Second {
    u8 pad[0x64];
    void* field;
};

class Object {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void call(int, int);
};

extern "C" void fn_27_13604C(void*, void*, void*, void*);

extern "C" void fn_119_8F10(void* self, void* arg2, void* arg3, void* arg4) {
    if (arg3) {
        void* a = static_cast<Root*>(self)->field;
        void* b = static_cast<First*>(a)->field;
        Object* obj = static_cast<Object*>(static_cast<Second*>(b)->field);
        obj->call(0, 0x10000040);
    }
    fn_27_13604C(self, arg2, arg3, arg4);
}
