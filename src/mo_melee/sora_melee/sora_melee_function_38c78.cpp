#pragma force_active on
extern "C" void __dl__FPv(void* p);

class clTarget {
public:
    virtual void fn_keyVirtual();
    virtual ~clTarget();
};

clTarget::~clTarget() { }
