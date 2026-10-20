#pragma force_active on
class grYakumono {
public:
    virtual ~grYakumono();
};

class grGimmickSpring : public grYakumono {
public:
    // Declared first and never defined, so the vtable is not emitted in this translation unit.
    virtual void keyFunc();
    virtual ~grGimmickSpring();
};

grGimmickSpring::~grGimmickSpring() { }
