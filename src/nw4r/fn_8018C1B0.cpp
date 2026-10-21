#pragma force_active on
extern "C" {
void fn_80204E6C(void* a, int b);
void fn_8018C1B0(void* self);
}

struct Foo {
    char a;
    char b;
    int c;
};

extern void* lbl_805A0508;

extern "C" void fn_8018C1B0(void* self) {
    Foo* foo = (Foo*)self;
    if (foo->c != 0) {
        fn_80204E6C(lbl_805A0508, foo->c);
        foo->c = 0;
        foo->a = 0;
        foo->b = 0;
    }
}
