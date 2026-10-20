#pragma force_active on
class grGimmick {
public:
    virtual ~grGimmick();
};

class grGimmickMotionPath : public grGimmick {
public:
    // Declared first so it becomes the vtable key function, which is defined
    // in another translation unit. Without it, the checker reports a multiply-defined vtable.
    virtual void keyFunc();
    virtual ~grGimmickMotionPath();
};

grGimmickMotionPath::~grGimmickMotionPath() {
}
