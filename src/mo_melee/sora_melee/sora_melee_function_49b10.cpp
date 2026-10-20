#pragma force_active on
extern "C" void fn_27_470AC(void* self, void* result, void* sub, void* arg);

class fn27Base {
public:
    virtual void* vf0(void* arg);
    virtual void* vf1(void* arg);
    virtual void* vf2(void* arg);
};

extern "C" {
void fn_27_49B10(void* self, char* obj, void* arg1, void* arg2) {
    fn27Base* o = *(fn27Base**)(obj + 0x48);
    void* sub = o->vf1(arg2);
    fn_27_470AC(self, sub, obj + 0x28, arg1);
}
}
