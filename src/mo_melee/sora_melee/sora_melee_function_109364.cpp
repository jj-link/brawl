#pragma force_active on
typedef unsigned char u8;

struct Data {
    char pad0[0xa];
    u8 a;
    char pad1[0xd5e - 0xb];
    u8 b;
};

struct Node {
    char pad[0x28];
    Data* data;
};

class Sub {
public:
    virtual void v2();
    virtual Node** v3(int i);
    virtual void v4();
    virtual int count();
};

struct Holder {
    int pad0;
    int pad1;
    Sub sub;
};

struct Self {
    char pad[0x6c];
    u8 flags;
    char pad2[0x154 - 0x6d];
    Holder* holder;
};

extern "C" void fn_27_109364(Self* self) {
    self->flags |= 0x20;
    int n = self->holder->sub.count();
    for (int i = 0; i < n; i++) {
        Node** pn = self->holder->sub.v3(i);
        Node* node = *pn;
        node->data->a = 0;
        node->data->b = 0;
    }
}
