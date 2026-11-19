#pragma force_active on
struct Node {
    char pad[12];
    int a;
    int unused;
    int b;
};

struct Input {
    Node* node;
    int value;
    int third;
};

struct Local {
    int a;
    int value;
    int third;
    const Input* input;
};

class Class_80486788 {
public:
    virtual void fn_802A39F0();
    virtual void fn_80080A64();
    virtual void fn_802A34B0();
    virtual void fn_802A3540();
    virtual void fn_802A3350();
    virtual void fn_802A3730();
    virtual void fn_802A221C();
    virtual void fn_802A38CC(Local*, int, int);
};

struct Owner {
    char pad[12];
    Class_80486788* first;
    Class_80486788* second;
};

inline void set(Local& l, int x, int y) {
    l.value = y;
    l.a = x;
}

extern "C" void fn_802A3290(Owner* owner, const Input* input, int a, int b) {
    Local local;
    local.third = input->third;
    Node* node = input->node;
    local.input = input;
    set(local, node->a, input->value);
    owner->first->fn_802A38CC(&local, a, b);
    if (owner->second) {
        set(local, node->b, local.input->value);
        owner->second->fn_802A38CC(&local, a, b);
    }
}
