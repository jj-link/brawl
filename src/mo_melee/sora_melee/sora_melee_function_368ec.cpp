#include <sr/sr_common.h>
#pragma force_active on

struct WorkData {
    char pad0[0x18];
    int value18;
    char pad1[0x1C];
    void* list38;
    char pad2[0x38];
    unsigned char value74;
};
class soNullable {
public:
    virtual void isNull();
    virtual WorkData* slot1(int);
    virtual void slot2();
};
class Class_CF8 {
public:
    virtual void fn_27_1000C();
    virtual void fn_27_100D0();
    virtual int fn_27_100CC();
};
struct Context {
    int value0;
    Class_CF8* object4;
    soNullable* object8;
    int valueC;
    unsigned char value10;
};
struct Vector3 { float x, y, z; };
struct Node {
    char pad[8];
    int value8, valueC;
    Vector3 position;
    unsigned short value1C, value1E;
    unsigned char value20, value21, value22, value23;
    unsigned char value24, value25, value26, value27;
    unsigned char value28, value29, value2A;
    void init(int a, int b, unsigned char c, unsigned char d, int e,
              const Vector3& p, unsigned char f) {
        value8 = a; valueC = b; value22 = c; value20 = d; value21 = e;
        value23 = 0; value1C = 0; value24 = 0; value25 = 0;
        value1E = 0; value26 = 0;
        position.x = p.x; position.y = p.y; position.z = p.z;
        value27 = 0; value28 = 1; value29 = 0; value2A = f;
    }
};
extern "C" {
extern void* lbl_27_bss_B8;
extern float lbl_27_rodata_478;
void* fn_27_4FAB4(void*);
Node* fn_27_500B8(void*);
void fn_8015BFB4(void*, void*);
void fn_27_368EC(Context* self, Context* other, int a, int b) {
    if (!lbl_27_bss_B8) {
        void* p = operator new(0x1508, Heaps::System);
        if (p) p = fn_27_4FAB4(p);
        lbl_27_bss_B8 = p;
    }
    int c;
    int d;
    int bb;
    int e;
    unsigned char f;
    Node* node = fn_27_500B8(lbl_27_bss_B8);
    f = other->object8->slot1(a)->value74;
    Vector3 v = {lbl_27_rodata_478, lbl_27_rodata_478, lbl_27_rodata_478};
    e = other->value0;
    c = other->object4->fn_27_100CC();
    d = c;
    c = other->value10;
    bb = other->valueC;
    int aa = other->object8->slot1(a)->value18;
    node->init(aa, bb, c, d, e, v, f);
    fn_8015BFB4(self->object8->slot1(b)->list38, node);
}
}
