#include <ut/ut_list.h>
#pragma force_active on

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
    virtual int fn_27_6A71C(int);
};

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual unsigned char* fn_27_14068(int);
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
};

struct Class_90D8_base { char pad[8]; };
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
    virtual int fn_27_7B22C();
};

extern "C" void* fn_27_6F30C(void*);

extern "C" int fn_27_6E66C(soNullable* self, int id) {
    if (id >= 0) {
        Class_1250* table = *(Class_1250**)((unsigned char*)self + 0x48);
        unsigned char* node = table->fn_27_14068(id) + 0x1c;
        unsigned char* p = *(unsigned char**)((unsigned char*)fn_27_6F30C(node) + 0x44);
        p = *(unsigned char**)(p + 0xd8);
        p = *(unsigned char**)(p + 0xb8);
        return ((Class_90D8*)p)->fn_27_7B22C();
    }
    if (self->fn_27_6A71C(-1)) {
        utListNode* node = ((utList*)((unsigned char*)self + 0x20))->getNode(0);
        while (node != 0) {
            unsigned char* item = *(unsigned char**)((unsigned char*)node + 0xc);
            if ((*(unsigned long*)(item + 0x30) >> 8) & 0x2000) {
                unsigned char* p = *(unsigned char**)((unsigned char*)fn_27_6F30C(node) + 0x44);
                p = *(unsigned char**)(p + 0xd8);
                p = *(unsigned char**)(p + 0xb8);
                return ((Class_90D8*)p)->fn_27_7B22C();
            }
            node = node->m_next;
        }
    }
    return 0;
}