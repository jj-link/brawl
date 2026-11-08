#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int);
};
struct Modules { char pad[0x64]; Object_vptr_0* work; };
struct Accesser { char pad[0xd8]; Modules* modules; };
extern "C" {
void fn_27_15FA20(int, int, Accesser*);
void fn_27_359014(int, int, Accesser*);
void fn_27_3BBC90(int, int, Accesser*);
void fn_27_3317DC(int, int, Accesser*);
void fn_27_346284(int, int, Accesser*);
void fn_27_3615F8(int, int, Accesser*);
void fn_27_32996C(int, int, Accesser*);
void fn_27_338FE0(int, int, Accesser*);
void fn_27_35A6FC(int, int, Accesser*);
void fn_96_20B50(int a, int b, Accesser* c) {
    if (a <= 99) {
        fn_27_15FA20(a, b, c);
    } else {
        switch (c->modules->work->slot4(0x10000048)) {
        case 22: fn_27_359014(a,b,c); break;
        case 47: fn_27_3BBC90(a,b,c); break;
        case 12: fn_27_3317DC(a,b,c); break;
        case 15: fn_27_346284(a,b,c); break;
        case 26: fn_27_3615F8(a,b,c); break;
        case 10: fn_27_32996C(a,b,c); break;
        case 13: fn_27_338FE0(a,b,c); break;
        case 23: fn_27_35A6FC(a,b,c); break;
        }
    }
}
}