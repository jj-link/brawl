#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry { u8 flags:1; u8 rest:7; bool enabled() const { return flags; } };
struct Array { virtual void dummy0(); virtual Entry* at(int); virtual void dummy2(); virtual int size(); };
struct Big { unsigned int x; unsigned int y; unsigned int z; Big() {} Big(const Big& o):x(o.x),y(o.y),z(o.z){} };
class Obj { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual Big getA(); virtual void v4(); virtual Big getB(); };
struct Mid { u8 pad[0xc]; Obj* obj; };
struct Holder { u8 pad[0xd8]; Mid* mid; };
struct Object { u8 pad[0x10]; Holder* holder; u8 flags:1; u8 rest:7; u8 pad15[3]; Array* entries; bool enabled() const { return flags; } };
extern "C" void fn_27_B4870(Object*);
extern "C" void fn_27_B180C(Entry*, Big*, Big*, Holder*, bool);
extern "C" void fn_27_B2530(Object* self) {
    if (self->enabled()) fn_27_B4870(self);
    int count = self->entries->size();
    Big a = self->holder->mid->obj->getA();
    Big b = self->holder->mid->obj->getB();
    Entry* entry;
    bool flag;
    int i;
    for (i = 0; i < count; i++) {
        entry = self->entries->at(i);
        flag = false;
        if (self->enabled() == true && self->entries->at(i)->enabled() == true) flag = true;
        fn_27_B180C(entry, &a, &b, self->holder, flag);
    }
}