#pragma force_active on
typedef unsigned int u32;

struct Data { u32 pad; u32 flags; };

struct Callback {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void setup(int, int);
    Data* data;
    u32 mode;
};

struct Obj;
struct VTable {
    char pad0[0xb0];
    void (*fn42)(Obj*, int);
    char padb4[0x8c];
    void (*fn78)(Obj*, const char*);
};

struct Obj {
    Obj(const char* name);
    char pad0[0x3c];
    VTable* vtable;
    char pad40[0x90];
    char part[0xc];
    char paddc[0x7c];
    char matrix[0x30];
    u32 field188;
};

namespace Heaps { enum HeapType { StageInstance = 15 }; }

extern void* operator new(unsigned long, Heaps::HeapType);
extern "C" void fn_66_2BFC(void*, const char*);
extern "C" void setIdentity__6MatrixFv(void*);
extern "C" VTable lbl_66_data_2CE0;

inline Obj::Obj(const char* name) {
    Obj* self = this;
    fn_66_2BFC(self, name);
    self->vtable = &lbl_66_data_2CE0;
    self->field188 = 0;
    setIdentity__6MatrixFv(self->matrix);
    Callback* cb = (Callback*)self->part;
    if (!cb)
        return;
    cb->mode = 1;
    cb->setup(0, 15);
    cb->data->flags |= 8;
}

struct Base { char pad[0x3c]; };
#define V(n) virtual void f##n();
struct CallObj : Base {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41)
    virtual void f42(int);
    V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77)
    virtual void f78(const char*);
};

extern "C" Obj* fn_66_F0C8(int mdl, const char* node, const char* name) {
    Obj* obj = new (Heaps::StageInstance) Obj(name);
    if (obj) {
        ((CallObj*)obj)->f42(mdl);
        ((CallObj*)obj)->f78(node);
    }
    return obj;
}
