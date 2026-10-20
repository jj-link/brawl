#pragma force_active on
extern "C" {
struct FooObj {
    unsigned char pad[8];
    unsigned int flag : 2;
};

void fn_27_CD800(FooObj* obj, unsigned int v) {
    obj->flag = v;
}
}
