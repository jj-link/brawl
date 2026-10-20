#pragma force_active on
extern "C" void fn_27_4AD90(int* value);

class Vtbl {
public:
    virtual void a() = 0;
    virtual int* at(int i) = 0;
    virtual void d() = 0;
    virtual int size() = 0;
};

extern "C" void fn_27_4B698(char* this_, int a, float f1, float f2, float f3, char b) {
    *(int*)(this_ + 0xcc) = a;
    *(float*)(this_ + 0x30) = f1;
    *(float*)(this_ + 0x34) = f2;
    *(float*)(this_ + 0x38) = f3;
    *(char*)(this_ + 0xe0) = b;
    for (int i = 0; i < (*(Vtbl**)(this_ + 0x2c))->size(); i++) {
        int* val = (*(Vtbl**)(this_ + 0x2c))->at(i);
        fn_27_4AD90(val);
    }
}
