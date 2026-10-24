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
    char pad[0x24];
    Obj* obj;
};

extern "C" void* fn_8005BF6C(Arg* arg) {
    void* node;
    Obj* obj = arg->obj;

    if (obj == 0) {
        return 0;
    }

    node = fn_8015C1B0(obj->listA, 0);
    if (node == 0) {
        node = 0;
    } else {
        obj->process(node);
        fn_8015C144(obj->listA, node);
        fn_8015BFB4(obj->listB, node);
    }

    return node;
}
