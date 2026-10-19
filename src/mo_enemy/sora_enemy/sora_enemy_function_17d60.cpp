#pragma force_active on
class Obj {
public:
    virtual void slot0();
    virtual void call(int);
};

extern "C" Obj* fn_41_15FD4(void*, int);

extern "C" void fn_41_17D60(void* a, int b) {
    if (b != -1) {
        Obj* obj = fn_41_15FD4(a, b);
        obj->call(*(int*)((char*)a + 0x20));
    }
}
