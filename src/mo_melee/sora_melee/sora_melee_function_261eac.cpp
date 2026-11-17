#pragma force_active on
typedef unsigned int u32;

struct Flags { u32 pad; u32 flags; };

struct Part {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void clear(int, int);
    Flags* data;
    u32 state;
};

struct VTable { int _data; };
extern VTable lbl_27_data_54A08;

struct Obj {
    Obj(const char* name);
    char pad0[0x3c];
    VTable* vtable;
    char pad40[0x90];
    char part[0xc];
    char paddc[0x74];
    u32 a150;
    u32 a154;
    u32 a158;
    u32 a15c;
};

namespace Heaps { enum HeapType { StageInstance = 15 }; }
extern void* operator new(unsigned long, Heaps::HeapType);
extern "C" void __ct__10grYakumonoFPCc(Obj*, const char*);

struct Base { char pad[0x3c]; };
#define V(n) virtual void f##n();
struct CallObj : Base {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25)
    virtual void setupMelee();
    V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36)
    V(37) V(38) V(39) V(40) V(41)
    virtual void setMdlIndex(int);
    V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52)
    V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62)
    V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72)
    V(73) V(74) V(75) V(76) V(77)
    virtual void setTgtNode(const char*);
};

inline Obj::Obj(const char* name) {
    Obj* self = this;
    __ct__10grYakumonoFPCc(self, name);
    self->vtable = &lbl_27_data_54A08;
    ((CallObj*)self)->setupMelee();
    self->a150 = 0;
    self->a154 = 0;
    self->a158 = 0;
    self->a15c = 0;
    Part* p = (Part*)self->part;
    if (!p)
        return;
    p->state = 1;
    p->clear(0, 15);
    p->data->flags |= 1;
    return;
}

extern "C" Obj* fn_27_261EAC(int arg0, const char* arg1, const char* arg2) {
    Obj* obj = new (Heaps::StageInstance) Obj(arg2);
    if (obj) {
        ((CallObj*)obj)->setMdlIndex(arg0);
        ((CallObj*)obj)->setTgtNode(arg1);
    }
    return obj;
}
