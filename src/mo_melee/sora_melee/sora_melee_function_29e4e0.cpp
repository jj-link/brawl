#pragma force_active on

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, int, int, int);
};

struct S {
    int a;
    int b;
    int c;
};

extern "C" int randi__Fl(int);
extern struct S lbl_27_rodata_4784;

extern "C" void fn_27_29E4E0(void* unused, char* self) {
    struct S local = lbl_27_rodata_4784;
    int* arr = (int*)&local;
    int idx = randi__Fl(3);
    (*(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x50))->v5(arr[idx], 0, 0, 0);
    (*(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x50))->v5(0x1fa6, 0, 0, 0);
}