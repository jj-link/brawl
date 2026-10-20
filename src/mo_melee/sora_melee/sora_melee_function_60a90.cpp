#pragma force_active on
struct Data {
    unsigned char a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned char e;
    unsigned int f;
    unsigned int g;
    unsigned int h;
    unsigned int i;
    unsigned int j;
};

extern "C" void fn_27_60A90(Data* dst, const Data* src) {
    dst->c = src->c;
    dst->d = src->d;
    dst->a = src->a;
    dst->b = src->b;
    dst->f = src->f;
    dst->e = src->e;
    dst->g = src->g;
    dst->h = src->h;
    dst->i = src->i;
    dst->j = src->j;
}
