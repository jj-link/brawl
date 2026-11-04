#pragma force_active on
struct Element;

struct Mid7 {
    unsigned char b73, b74, b75, b76, b77, b78, b79;
};

struct ElementBody {
    unsigned char b4;
    unsigned int w8, wC, w10, w14, w18, w1C, w20, w24, w28, w2C, w30, w34, w38, w3C, w40, w44, w48, w4C, w50, w54;
    unsigned char b58, b59, b5A, b5B, b5C, b5D, b5E, b5F, b60, b61, b62, b63, b64, b65, b66, b67, b68, b69, b6A, b6B, b6C, b6D, b6E, b6F, b70, b71, b72;
    Mid7 mid;
    unsigned char b7A, b7B, b7C, b7D, b7E, b7F, b80, b81, b82, b83, b84, b85, b86, b87, b88, b89;
};

class Array {
public:
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual int size();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual int v3c();
    virtual bool v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual Element* at(int);
    virtual int v74();
    virtual int v78();
    virtual void setSize(int);
};

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, int, bool, int, int, int, int);

extern "C" void fn_27_1B84E0(Array* self, int index, const Element* value) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        (char*)self + 4, index, self->v40(), self->size(),
        self->v3c(), self->v74(), self->v78());
    ElementBody* dst = (ElementBody*)((char*)self->at(pos) + 4);
    const ElementBody* src = (const ElementBody*)((const char*)value + 4);
    *dst = *src;
    self->setSize(self->size() + 1);
}
