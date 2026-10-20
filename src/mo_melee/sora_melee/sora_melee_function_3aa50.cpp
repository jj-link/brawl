#pragma force_active on
class soSubObj {
public:
    virtual void vf0();
    virtual soSubObj* vf1();
};

typedef unsigned int u32;

extern "C" {
u32 fn_27_3AA50(char* self, u32 unused, u32 n) {
    if (n == 1) {
        soSubObj* o = *(soSubObj**)(self + 0x34);
        char* p = (char*)o->vf1();
        return *(u32*)(p + 0x1c);
    }
    soSubObj* o = *(soSubObj**)(self + 0x30);
    char* p = (char*)o->vf1();
    return *(u32*)(p + 0x20);
}
}
