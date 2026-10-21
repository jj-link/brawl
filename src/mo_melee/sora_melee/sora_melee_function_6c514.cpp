#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void* getNode__6utListFUl(void*, u32);
extern "C" void* fn_27_6F30C(void*);

#define V(n) virtual u32 v##n();
#define V10(a) V(a##0) V(a##1) V(a##2) V(a##3) V(a##4) V(a##5) V(a##6) V(a##7) V(a##8) V(a##9)

class Acc {
public:
    V10() V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87)
    virtual u32 v88();
};

struct Tgt {
    u8 pad[8];
    V10() V10(1) V10(2) V10(3) V10(4)
    V(50) V(51)
    virtual void target(u32);
};

extern "C" void fn_27_6C514(void* self, u32 arg) {
    void* node = getNode__6utListFUl((u8*)self + 0x14, 0);
    while (node != 0) {
        Acc* obj = (Acc*)fn_27_6F30C(node);
        if (obj->v88() == 1) {
            void* o = *(void**)((u8*)fn_27_6F30C(node) + 0x44);
            o = *(void**)((u8*)o + 0xd8);
            Tgt* t = *(Tgt**)((u8*)o + 0x9c);
            t->target(arg);
        }
        node = *(void**)node;
    }
}
