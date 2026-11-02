#pragma force_active on
struct Elem {
    unsigned char a;
    char pad0[0x16];
    unsigned char b;
    char pad1[2];
    unsigned char c;
    char pad2;
    unsigned char d;
    char pad3;
    short e;
    int f;
    char pad4[4];
};

struct Data {
    unsigned char h0;
    unsigned char h1;
    unsigned char h2;
    unsigned char h3;
    char pad[4];
    Elem elems[32];
};

struct Obj {
    char pad[0x2c];
    Data* data;
};

extern "C" void fn_8004DDEC(Obj* obj) {
    obj->data->h0 = 0;
    obj->data->h1 = 0;
    obj->data->h2 = 0;
    obj->data->h3 = 0;
    for (int i = 0; i < 32; i++) {
        Elem* e = &obj->data->elems[i];
        e->a = 0;
        e->b = 0x78;
        e->c = 0;
        e->d = 0;
        e->e = 0;
        e->f = -1;
    }
}
