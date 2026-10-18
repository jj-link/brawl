#pragma force_active on
extern "C" {

struct T {
    int a;
    int b;
    int c;
};

int fn_63_B0E4(struct T *t)
{
    return t->c >> 28;
}

}
