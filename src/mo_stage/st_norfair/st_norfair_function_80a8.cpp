#pragma force_active on
class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    static void clear(soArrayVectorCalcInterface& calc);
};

class fn_54_Obj {
public:
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
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31(int v);
    int m_4;
};

extern "C" void fn_54_80A8(fn_54_Obj* self) {
    soArrayVectorCalculator::clear(*reinterpret_cast<soArrayVectorCalcInterface*>(&self->m_4));
    self->vf31(0);
}
