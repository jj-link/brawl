#pragma force_active on
class Class_80466780 {
public:
    virtual void fn_801C0CEC(int);
    char padding[0xB4];
    void* fieldB8;
};
extern "C" void fn_801C0A68(void*, void*);
extern "C" void fn_801C2134(char* self, Class_80466780* object) {
    object->fieldB8 = 0;
    if (object != 0) {
        object->fn_801C0CEC(-1);
        fn_801C0A68(self + 8, object);
    }
}
