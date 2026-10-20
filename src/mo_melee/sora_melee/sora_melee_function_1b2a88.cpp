#pragma force_active on
class wnPikminPikmin;

template <typename T>
class soArrayVectorAbstract {
public:
    virtual ~soArrayVectorAbstract();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual T at_virtual(long index) const;
    T at(long index) const;
};

template <typename T>
T soArrayVectorAbstract<T>::at(long index) const {
    return at_virtual(index);
}

template wnPikminPikmin* soArrayVectorAbstract<wnPikminPikmin*>::at(long index) const;
