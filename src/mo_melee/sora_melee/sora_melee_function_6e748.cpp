#include <types.h>
#include <ut/ut_list.h>
#pragma force_active on

class Class_90D8_base { public: char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
 virtual void fn_27_7B274();
 virtual void fn_27_7AC18();
 virtual void fn_27_7AC28();
 virtual void fn_27_7AB50();
 virtual void fn_27_7B2EC();
 virtual void fn_27_7AB10();
 virtual void fn_27_7AD2C();
 virtual void fn_27_7AEDC();
 virtual void fn_27_7B22C();
 virtual void fn_27_7AC38();
 virtual void fn_27_7ADE8();
 virtual void fn_27_7AF98();
 virtual void fn_27_7B0B0();
 virtual float fn_27_7ABD8();
 virtual unsigned char fn_27_7ABCC();
};
class Class_1250 {
public:
 virtual void fn_27_13C90();
 virtual void* fn_27_14068(int);
 virtual void fn_27_140C0();
 virtual void fn_27_1412C();
 virtual void fn_27_14134();
 virtual void fn_27_14370();
 virtual void fn_27_14A28();
 virtual void fn_27_14A30();
 virtual void fn_27_14A38();
 virtual void fn_27_14A48();
};
class soNullable {
public:
 virtual void isNull();
 virtual void fn_27_6A3D8();
 virtual void fn_27_6A4BC();
 virtual void fn_27_6A51C();
 virtual void fn_27_6A5E0();
 virtual void fn_27_6A640();
 virtual void fn_27_6A660();
 virtual void fn_27_6A650();
 virtual void fn_27_6A6DC();
 virtual bool fn_27_6A71C(int);
};
extern "C" void* fn_27_6F30C(void*);
extern "C" bool fn_27_6E748(soNullable* self, float* out, unsigned char* flag, int index) {
 if (index >= 0) {
    char* obj = (char*)((Class_1250*)*(void**)((char*)self + 0x48))->fn_27_14068(index);
    *out = ((Class_90D8*)*(void**)((char*)*(void**)((char*)*(void**)((char*)fn_27_6F30C(obj + 0x1c) + 0x44) + 0xd8) + 0xb8))->fn_27_7ABD8();
    *flag = ((Class_90D8*)*(void**)((char*)*(void**)((char*)*(void**)((char*)fn_27_6F30C(obj + 0x1c) + 0x44) + 0xd8) + 0xb8))->fn_27_7ABCC();
    return true;
 }
 if (self->fn_27_6A71C(-1)) {
    char* node = (char*)((utList*)((char*)self + 0x20))->getNode(0);
    while (node != 0) {
       if ((*(u32*)(*(char**)(node + 0xc) + 0x30) >> 8) & 0x2000) {
          *out = ((Class_90D8*)*(void**)((char*)*(void**)((char*)*(void**)((char*)fn_27_6F30C(node) + 0x44) + 0xd8) + 0xb8))->fn_27_7ABD8();
          *flag = ((Class_90D8*)*(void**)((char*)*(void**)((char*)*(void**)((char*)fn_27_6F30C(node) + 0x44) + 0xd8) + 0xb8))->fn_27_7ABCC();
          return true;
       }
       node = *(char**)node;
    }
 }
 return false;
}