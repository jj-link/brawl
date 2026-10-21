#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

class TargetObj {
public:
    virtual void f0();
    virtual void* call();
};

extern "C" s32 fn_27_3A430(void* self, void* arg2, u32 param) {
    TargetObj* obj;
    if (param == 1) {
        obj = *(TargetObj**)((char*)self + 0x34);
        void* result = obj->call();
        return *(u8*)((char*)result + 0x64);
    } else {
        obj = *(TargetObj**)((char*)self + 0x30);
        s32 ret = 0;
        void* result = obj->call();
        if (*(void**)result != 0) {
            if (((*(u32*)((char*)self + 0x9c)) >> 30) & 1) {
            } else {
                ret = 1;
            }
        }
        return ret;
    }
}
