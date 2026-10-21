#pragma force_active on
extern "C" void fn_801C7EC8(void*, void*, void*);

extern "C" {

struct A {
    void* _0x00;
    void* _0x04;
};

struct B {
    int _0x00[13];
    void* _0x34;
};

void fn_801C6BBC(A* a, void* arg) {
    B* b = (B*)a->_0x04;
    fn_801C7EC8(b, b->_0x34, arg);
}

}
