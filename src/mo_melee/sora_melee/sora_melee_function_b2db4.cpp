#pragma force_active on

typedef unsigned int u32;
typedef int s32;

class ArrIf {
public:
    virtual void v0() = 0;
    virtual void* atC(s32 i) = 0;
    virtual void v2() = 0;
    virtual s32 size() = 0;
};

struct Container {
    char pad[0x18];
    ArrIf* arr;
};

extern "C" void fn_27_B1E48(void* self, u32 v);

extern "C" void fn_27_B2DB4(Container* c, s32 id, s32 idx) {
    if (idx == -1) {
        s32 n = c->arr->size();
        for (s32 i = 0; i < n; i++) {
            fn_27_B1E48(c->arr->atC(i), (u32)id);
        }
    }
    else {
        fn_27_B1E48(c->arr->atC(idx), (u32)id);
    }
}
