#pragma force_active on
extern "C" {

#define D1(n) virtual void v##n();
#define D10(a) D1(a##0) D1(a##1) D1(a##2) D1(a##3) D1(a##4) D1(a##5) D1(a##6) D1(a##7) D1(a##8) D1(a##9)

struct NP { char x[0x3c]; };

class C : public NP {
public:
    D10(0) D10(1) D10(2) D10(3) D10(4) D10(5) D10(6) D10(7) D10(8)
    D1(90) D1(91) D1(92) D1(93) D1(94) D1(95)
    virtual void target(int, int);
    char pad[0x150 - 0x40];
    unsigned char unk150;
    char pad2[0x194 - 0x151];
    void** unk194;
};

void fn_51_BFCC(C* c)
{
    if (c->unk194 == 0)
        return;
    if (*(unsigned char*)c->unk194 != 0)
        return;
    if (c->unk150 != 1)
        return;
    return c->target(0, 0);
}

}
