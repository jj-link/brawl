#pragma force_active on
extern "C" void* fn_8015C1B0(void*, void*);
extern "C" void fn_8015C144(void*, void*);
extern "C" void fn_8015BFB4(void*, void*);

class Obj {
public:
    char pad[4];
    char listA[0xC];
    char listB[0x10];

    virtual void process(void*);
};

struct Arg {
    char pad[0xC];
    Obj* obj;
};

extern "C" void* fn_8005C20C(Arg* arg) {
    void* res;
    Obj* o = arg->obj;
    if (o == 0) {
        return 0;
    }

    res = fn_8015C1B0(o->listA, 0);
    if (res == 0) {
        res = 0;
    } else {
        o->process(res);
        fn_8015C144(o->listA, res);
        fn_8015BFB4(o->listB, res);
    }
    return res;
}
