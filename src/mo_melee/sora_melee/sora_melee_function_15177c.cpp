#pragma force_active on
class soModuleAccesser;

extern "C" int fn_27_61334(soModuleAccesser*, int);

class soVirtObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(int, soModuleAccesser*);
};

class soModuleMid {
public:
    char pad[0x70];
    soVirtObj* obj;
};

class soModuleAccesser {
public:
    char pad[0xd8];
    soModuleMid* mid;
};

extern "C" {
    void fn_27_15177C(int a, int b, soModuleAccesser* accesser) {
        int result = fn_27_61334(accesser, b);
        accesser->mid->obj->vf3(result, accesser);
    }
}
