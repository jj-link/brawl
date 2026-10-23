#pragma force_active on
extern "C" void* fn_8015C1B0(void*, void*);
extern "C" void fn_8015C144(void*, void*);
extern "C" void fn_8015BFB4(void*, void*);

class Obj {
public:
    char pad0[4];
    char sub[0xC];
    char sub2[0x10];

    virtual void process(void*);
};

struct Arg {
    char pad[0x18];
    Obj* obj;
};

extern "C" void* fn_8005C0BC(Arg* arg) {
    void* node;
    Obj* obj = arg->obj;

    if (obj == 0) {
        return 0;
    }

    node = fn_8015C1B0(obj->sub, 0);
    if (node == 0) {
        node = 0;
    } else {
        obj->process(node);
        fn_8015C144(obj->sub, node);
        fn_8015BFB4(obj->sub2, node);
    }

    return node;
}
