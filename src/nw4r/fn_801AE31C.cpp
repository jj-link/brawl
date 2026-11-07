#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int, void*, void*, void*);
};

static inline u32 roundSize(u32 n) { return (n + 0x1f) & ~0x1f; }

struct Obj {
    u8 pad[0xd4];
    Object_vptr_0* cb;
    u8 flagsD8;
    u8 padD9;
    u16 flagsDA;
    u8 padDC[0xc];
    u32 valE8;
    char* ec;
    char* f0;
    char* f4;
    char* f8;
    char* fc;
    u8 count;
    u8 idx;
    u16 num;
    u32 flags104;

    void* getF4() const { return f4 + idx * roundSize(num * 0x30); }
    void* getF8() const { return f8 ? f8 + idx * roundSize(num * 0x24) : 0; }
    void* getFC() const { return fc ? fc + idx * roundSize(num * 0x30) : 0; }
};

extern "C" {
void fn_801AAB18(void*, void*);
int fn_8015D804();
void fn_8015D874();
void fn_801D7718(void*, u32);
void fn_801A4204(void*, void*, void*, void*, u32, void*, u32*, void*);
void fn_801A3D68(void*, void*, void*, void*, u32, void*, u32*, void*);
void fn_801A3A44(void*, void*, void*, void*, u32, void*, u32*, void*);
}

extern "C" void fn_801AE31C(Obj* o, void* a1, void* a2) {
    o->idx = (o->idx + 1) % o->count;
    if (o->cb && (o->flagsDA & 4) && (o->flagsD8 & 1))
        o->cb->slot3(1, o, a1, a2);
    fn_801AAB18(o, a2);
    if (o->cb && (o->flagsDA & 4) && (o->flagsD8 & 2))
        o->cb->slot3(2, o, a1, a2);
    if (fn_8015D804()) {
        if (o->flags104 & 1) {
            fn_801D7718(o->ec, o->num * 0x30);
            void* p4 = o->getF8();
            void* p10 = o->getFC();
            u32 v = o->valE8;
            fn_801A4204(o->getF4(), p4, o->ec, o->f0, o->num, a2, &v, p10);
        } else {
            void* p4 = o->getF8();
            void* p10 = o->getFC();
            u32 v = o->valE8;
            fn_801A3D68(o->getF4(), p4, o->ec, o->f0, o->num, a2, &v, p10);
        }
        fn_8015D874();
    } else {
        void* p4 = o->getF8();
        void* p10 = o->getFC();
        u32 v = o->valE8;
        fn_801A3A44(o->getF4(), p4, o->ec, o->f0, o->num, a2, &v, p10);
    }
    if (o->cb && (o->flagsDA & 4) && (o->flagsD8 & 4))
        o->cb->slot3(4, o, a1, a2);
}
