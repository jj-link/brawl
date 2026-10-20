#pragma force_active on
typedef unsigned char u8;

struct Child {
    u8 pad[0x10A0];
    u8 flag;
};

struct Object {
    u8 pad[0x68];
    u8 b68, b69, b6a, b6b;
    u8 f6c : 4;
    u8 rest6c : 4;
    u8 b6d;
    u8 f6e : 5;
    u8 f6e2 : 1;
    u8 f6e1 : 1;
    u8 f6e0 : 1;
    u8 f6f7 : 1;
    u8 f6f65 : 2;
    u8 f6f4 : 1;
    u8 f6frest : 4;
    u8 pad70[0xC];
    u8 b7c;
    u8 pad7d[0xDF];
    Child* child;
};

extern "C" void fn_27_1090EC(Object* p) {
    p->b68 = 0;
    p->b69 = 0;
    p->b7c = 0;
    p->b6d = 0;
    p->f6c = 0;
    p->f6e = 0;
    p->f6e0 = 0;
    p->f6f7 = 0;
    p->f6f4 = 1;
    p->f6e2 = 0;
    p->b6b = 0;
    p->b6a = 0;
    p->child->flag = 1;
}
