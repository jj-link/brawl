#include <types.h>
#pragma force_active on

extern "C" void fn_41_30254(void* self, int a, int b, void* c, void* d);
extern "C" char lbl_41_data_C8CC[];
extern "C" char lbl_41_data_3E50[];

struct Msg {
    int kind;
    int id;
    void* ptr;
    void* obj;
};

class Sub {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual s16 vf7();
};

extern "C" {
void* fn_41_40190(void* self, char* p4) {
    *(void**)self = lbl_41_data_C8CC;
    void* obj = *(void**)(*(char**)(p4 + 0xd8) + 0xc0);

    Msg m;
    m.kind = 1;
    m.id = 0x17;
    m.ptr = &m.kind;
    m.obj = obj;

    Sub* sub = *(Sub**)(*(char**)(p4 + 0xd8) + 0x80);
    s16 r = ((Sub*)((char*)sub + 8))->vf7();

    fn_41_30254((char*)self + 4, 0, (int)r, &m.ptr, lbl_41_data_3E50);
    return self;
}
}
