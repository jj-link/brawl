#pragma force_active on
extern "C" {

struct Pair {
    int a;
    int b;
};

struct Inner {
    char c0;
    char c1;
    char c2;
    Pair p[5];
    char d0;
    char d1;
    char d2;
};

struct Outer {
    int head;
    Inner inner;
};

void fn_105_1C734(Outer *dst, Outer *src)
{
    dst->inner = src->inner;
}

}

