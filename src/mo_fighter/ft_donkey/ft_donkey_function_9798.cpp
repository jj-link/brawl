#pragma force_active on
struct P {
    char pad[0x3c];
};

#define V(n) virtual void v##n();
#define G4(n) V(n##0) V(n##1) V(n##2) V(n##3)
#define G16(n) G4(n##0) G4(n##1) G4(n##2) G4(n##3)
#define G64(n) G16(n##0) G16(n##1) G16(n##2) G16(n##3)

class D : public P {
public:
    G64(0)
    G64(1)
    G16(2)
    G16(3)
    G4(4)
    G4(5)
    G4(6)
    G4(7)
    G4(8)
    G4(9)
    virtual void va();
    virtual void vb();
    virtual void proc();
};

extern "C" void fn_92_9798(D* d) {
    d->proc();
}
