#pragma force_active on
extern "C" {
typedef struct S {
    unsigned char pad[0xa4];
    unsigned char a : 1;
    unsigned char b : 1;
} S;
bool fn_109_1150C(void* self)
{
    S* p = (S*)self;
    return p->b;
}
}
