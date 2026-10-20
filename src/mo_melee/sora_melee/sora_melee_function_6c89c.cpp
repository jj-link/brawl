#pragma force_active on
struct Result {
    float x, y, z;
};

struct Node;

struct Lookup {
    virtual void unused();
    virtual Node* get(int);
};

struct Context {
    char pad[0x48];
    Lookup* lookup;
};

struct Target {
    virtual void unused00();
    virtual void unused01();
    virtual void unused02();
    virtual void unused03();
    virtual void unused04();
    virtual void unused05();
    virtual void unused06();
    virtual void unused07();
    virtual void unused08();
    virtual void unused09();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual Result get(int);
};

struct Holder {
    char pad[0x0c];
    Target* target;
};

struct Data {
    char pad[0xd8];
    Holder* holder;
};

struct Accessor {
    char pad[0x44];
    Data* data;
};

extern "C" Accessor* fn_27_6F30C(void*);

inline Data* getData(void* node) {
    return fn_27_6F30C(node)->data;
}

extern "C" Result fn_27_6C89C(Context* context, int index) {
    Node* node = context->lookup->get(index);
    Data* data = getData((char*)node + 0x1c);
    Target* target = data->holder->target;
    return target->get(0);
}
