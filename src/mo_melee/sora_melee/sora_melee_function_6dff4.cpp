#include <types.h>
#pragma force_active on

struct Vec2 {
    f32 x;
    f32 y;
};

class Pad8 {
public:
    u32 a;
    u32 b;
};

class YObj : public Pad8 {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual Vec2 fn_27_160(u32 arg);
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_6A3D8();
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
    virtual void fn_27_6BD6C();
    virtual void fn_27_6AE24();
    virtual void fn_27_6B22C();
    virtual void fn_27_6B66C();
    virtual void fn_27_6BA10();
    virtual void fn_27_6BA7C();
    virtual void fn_27_6BAEC();
    virtual void fn_27_6BB6C();
    virtual void fn_27_6BBEC();
    virtual void fn_27_6BDD0();
    virtual void fn_27_6BE68();
    virtual void fn_27_6BEE4();
    virtual void fn_27_6BF60();
    virtual void fn_27_6BFDC();
    virtual void fn_27_6C084();
    virtual void fn_27_6C11C();
    virtual void fn_27_6C1B4();
    virtual void fn_27_6C24C();
    virtual void fn_27_6C2E8();
    virtual void fn_27_6C384();
    virtual void fn_27_6C480();
    virtual void fn_27_6C514();
    virtual void fn_27_6C5AC();
    virtual void fn_27_6C634();
    virtual void fn_27_6C6F4();
    virtual void fn_27_6C748();
    virtual void fn_27_6C79C();
    virtual void fn_27_6C7F0();
    virtual void fn_27_6C858();
    virtual void fn_27_6C89C();
    virtual void fn_27_6C908();
    virtual void fn_27_6C960();
    virtual void fn_27_6C9B8();
    virtual void fn_27_6EA30();
    virtual void fn_27_6CA10();
    virtual void fn_27_6CA64();
    virtual void fn_27_6CAB8();
    virtual void fn_27_6CB10();
    virtual void fn_27_6DF40();
    virtual void fn_27_6DF9C();
    virtual u32 fn_27_6DFF4(u32 arg1, Vec2* arg2);
};

extern "C" void* getNode__6utListFUl(void*, u32);
extern "C" void* fn_27_6F30C(void*);

extern "C" s32 fn_27_6DFF4(void* self, u32 arg1, Vec2* arg2) {
    u8* node = (u8*)getNode__6utListFUl((u8*)self + 0x20, 0);
    while (node != NULL) {
        u8* obj = *(u8**)(node + 0xc);
        u8* p = obj + 0x1c;
        if (arg1 == *(u32*)(p + 0x8)) {
            u8* acc = (u8*)fn_27_6F30C(p);
            YObj* y = *(YObj**)(*(u8**)(*(u8**)(acc + 0x44) + 0xd8) + 0x10);
            Vec2 v = y->fn_27_160(0);
            arg2->x = v.x;
            arg2->y = v.y;
            return 1;
        }
        {
            u8* acc = (u8*)fn_27_6F30C(p);
            soNullable* w = *(soNullable**)(*(u8**)(*(u8**)(acc + 0x44) + 0xd8) + 0x54);
            if (w->fn_27_6DFF4(arg1, arg2) == 1) {
                return 1;
            }
        }
        node = *(u8**)node;
    }
    return 0;
}
