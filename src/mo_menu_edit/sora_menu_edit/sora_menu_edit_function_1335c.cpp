#include <mu/mu_object.h>
#include <gf/gf_file_io_handle.h>
#include <ms/ms_message.h>
#include <string.h>
#include <stdio.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_5_data_E24[];
extern char lbl_5_data_E28[];
extern f32 lbl_5_rodata_300;
void fn_6_535C(void* self, void* buf, int len);
void* fn_6_8180(void* self, void* out);
}

struct Result {
    char data[0x44];
};

struct Child {
    char pad0[8];
    u8 kind;
};

struct Entry {
    char pad0[0xC];
    Child* child;
    char pad10[4];
    u8 flag;
};

struct Name {
    char s[65];
};

struct OutBuf {
    char text[0x200];
    int len;
};

struct AnimSlots {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8(float f);
};

struct Data {
    char pad0[0x17C];
    MuObject* object;
    char pad180[0x1C8 - 0x180];
    char sub1C8[0x1BFC - 0x1C8];
    int state;
    char pad1C00[0x1C90 - 0x1C00];
    gfFileIOHandle handle1C90;
    char pad1C94[0x1CC0 - 0x1C94];
    gfFileIOHandle handle1CC0;
    char pad1CC4[0x1D40 - 0x1CC4];
    int a1D40;
    int a1D44;
    int a1D48;
};

struct Base {
    char pad[0x3c];
};

struct Menu : Base {
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual int f41();
    virtual Result f42(int);
    virtual void f43();
    virtual void f44(int);

    char pad40[0x16c];
    Data* data;
};

extern "C" void fn_5_1335C(Menu* self) {
    OutBuf out;
    int ret = self->f41();
    if (ret < 0) {
        self->data->state = 0;
        return;
    }
    const Result& buf = self->f42(ret);
    Entry* entry = (Entry*)fn_6_8180(self->data->sub1C8, (void*)&buf);
    if (entry->flag == 0) {
        return;
    }
    out.len = 0;
    Child* child = entry->child;
    if (child == NULL) {
        u32 slen;
        char* str;
        Message::getPrintIndexData(self->data->handle1CC0.getBuffer(), 0x3A, &str, &slen);
        u32 n = slen;
        int len = out.len;
        memcpy(out.text + len, str, n);
        int total = len + n;
        out.len = total;
        fn_6_535C(self, out.text, total);
        return;
    }
    int kind = child->kind;
    switch (kind) {
    case 0: {
        MuObject* obj = self->data->object;
        self->f44((int)obj->m_sceneModel);
        char* mdl = *(char**)((char*)obj + 8);
        int off = *(int*)(mdl + 0x3c);
        const char* src = off ? mdl + off : 0;
        Name n;
        n.s[0] = 0;
        strcat(n.s, src);
        Name n2 = n;
        strcat(n2.s, lbl_5_data_E28);
        Name n3 = n2;
        sprintf(n3.s + strlen(n3.s), lbl_5_data_E24, 0);
        Name n4 = n3;
        obj->changeClrAnimNIf(n4.s);
        char* mdl2 = *(char**)((char*)obj + 8);
        int off2 = *(int*)(mdl2 + 0x3c);
        const char* src2 = off2 ? mdl2 + off2 : 0;
        Name n5;
        n5.s[0] = 0;
        strcat(n5.s, src2);
        Name n6 = n5;
        strcat(n6.s, lbl_5_data_E28);
        Name n7 = n6;
        sprintf(n7.s + strlen(n7.s), lbl_5_data_E24, 0);
        Name n8 = n7;
        obj->changeNodeAnimNIf(n8.s);
        AnimSlots* anim = (AnimSlots*)obj->m_modelAnim->m_anmObjChrRes;
        anim->s8(lbl_5_rodata_300);
        obj->setFrameNode(lbl_5_rodata_300);
        self->data->state = 0x18;
        break;
    }
    case 1:
    case 2: {
        u32 slen;
        char* str;
        Message::getPrintIndexData(self->data->handle1C90.getBuffer(), 5, &str, &slen);
        u32 n = slen;
        int len = out.len;
        memcpy(out.text + len, str, n);
        int total = len + n;
        out.len = total;
        fn_6_535C(self, out.text, total);
        break;
    }
    case 3:
        self->data->a1D40 = 1;
        self->data->a1D44 = 4;
        self->data->a1D48 = 0;
        self->data->state = 0x19;
        break;
    }
}
