#pragma force_active on
class ftPokeObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

extern "C" {
ftPokeObj* fn_116_104B0(void* p);
}

extern "C" void fn_116_115B4(void* self) {
    ftPokeObj* obj = fn_116_104B0((char*)self + 0x1344);
    obj->vf6();
}
