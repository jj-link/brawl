#include <types.h>
#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void* fn_27_6A3D8();
    virtual void fn_27_6A4BC();
    virtual void fn_27_6A51C();
    virtual void fn_27_6A5E0();
    virtual void fn_27_6A640();
    virtual void fn_27_6A660();
    virtual void fn_27_6A650();
    virtual void fn_27_6A6DC();
    virtual void fn_27_6A71C();
    virtual void fn_27_6A770();
    virtual void fn_27_6BC40();
    virtual void fn_27_6BC94();
    virtual void fn_27_6BCF8();
};

struct Res { u32 a; u32 b; };

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual Res slot13(u16*);
};

struct Modules { u8 pad[0x7C]; Object_vptr_0* module; };
struct Data { u8 pad[0xD8]; Modules* modules; };
struct Accessor { u8 pad[0x44]; Data* data; };
struct Owner { u8 pad[0x48]; soNullable* provider; };

extern "C" Accessor* fn_27_6F30C(void*);

extern "C" Res fn_27_6C7F0(Owner* owner) {
    u16 id;
    void* node = owner->provider->fn_27_6A3D8();
    id = 1;
    Res r = fn_27_6F30C((char*)node + 0x1C)->data->modules->module->slot13(&id);
    return r;
}
