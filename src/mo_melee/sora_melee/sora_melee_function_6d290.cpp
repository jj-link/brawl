#include <types.h>
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

class Class_A0 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual int s3();
};

extern "C" void* fn_27_6F30C(void*);

extern "C" int fn_27_6D290(void* arg0, s32 arg1) {
    if (arg1 >= 0) {
        Class_1250* table = *(Class_1250**)((unsigned char*)arg0 + 0x48);
        unsigned char* node = table->fn_27_14068(arg1) + 0x1c;
        unsigned char* p = (unsigned char*)fn_27_6F30C(node);
        p = *(unsigned char**)(p + 0x44);
        p = *(unsigned char**)(p + 0xd8);
        p = *(unsigned char**)(p + 0xa0);
        return ((Class_A0*)p)->s3();
    }
    if (((soNullable*)arg0)->fn_27_6A71C(-1)) {
        utListNode* node = ((utList*)((unsigned char*)arg0 + 0x20))->getNode(0);
        while (node != 0) {
            unsigned char* item = *(unsigned char**)((unsigned char*)node + 0xc);
            if ((*(u32*)(item + 0x30) >> 8) & 0x20) {
                unsigned char* p = (unsigned char*)fn_27_6F30C(node);
                p = *(unsigned char**)(p + 0x44);
                p = *(unsigned char**)(p + 0xd8);
                p = *(unsigned char**)(p + 0xa0);
                return ((Class_A0*)p)->s3();
            }
            node = node->m_next;
        }
    }
    return 0;
}
