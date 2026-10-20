#pragma force_active on
struct Inner {
    char pad[0x54];
    int count;
};

struct Outer {
    Inner* inner;
};

extern "C" {
void fn_27_112FD0(Outer* p) {
    Inner* obj = p->inner;
    if (obj->count > 0) {
        obj->count--;
    }
}
}
