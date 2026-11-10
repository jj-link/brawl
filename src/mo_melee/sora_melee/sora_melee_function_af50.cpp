#include <types.h>
#include <mt/mt_matrix.h>
#pragma force_active on

struct soModelModuleBase {
    char pad[8];
};

class soModelModuleImpl : public soModelModuleBase {
public:
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void vfn5(unsigned long a);
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void vfn42(unsigned long node, Matrix* out, bool flag);

    void getNodeLocalMtxFromNode(unsigned long a, unsigned long b, Matrix* out, bool flag);
};

void soModelModuleImpl::getNodeLocalMtxFromNode(unsigned long a, unsigned long b, Matrix* out, bool flag) {
    Matrix mA(true);
    Matrix mB(true);
    Matrix mInv(true);

    if (!flag) {
        vfn5(a);
        vfn5(b);
    }
    vfn42(b, &mB, false);
    vfn42(a, &mA, false);
    mA.inverse(&mInv);
    mInv.mul(&mB, out);
}
