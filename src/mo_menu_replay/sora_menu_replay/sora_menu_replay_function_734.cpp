#include <mu/mu_object.h>
#include <gf/gf_file_io_handle.h>
#include <ms/ms_message.h>
#include <snd/snd_system.h>
#include <string.h>
#include <stdio.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_7_data_6C8[];
extern char lbl_7_data_6CC[];
void fn_6_535C(void*, void*, int);
void* fn_6_8180(void*, void*);
}
struct Result { char data[0x44]; };
struct Entry { char pad[0xc]; void* child; char pad10[4]; u8 flag; };
struct Name { char s[65]; };
struct OutBuf { char text[0x200]; int len; };
struct Data {
    char pad0[0x164];
    MuObject* object;
    char pad168[0x1c8-0x168];
    char sub1C8[0x1bfc-0x1c8];
    int state;
    char pad1c00[0x1cc0-0x1c00];
    gfFileIOHandle handle;
};
struct Base { char pad[0x3c]; };
struct Menu : Base {
    virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
    virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13();
    virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17();
    virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21();
    virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25();
    virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29();
    virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33();
    virtual void f34(); virtual void f35(); virtual void f36(); virtual void f37();
    virtual void f38(); virtual void f39(); virtual void f40();
    virtual int f41();
    virtual Result f42(int);
    virtual void f43();
    virtual void f44(int);
    char pad40[0x16c];
    Data* data;
};
extern "C" void fn_7_734(Menu* self) {
    OutBuf out;
    int ret = self->f41();
    const Result& buf = self->f42(ret);
    Entry* entry = (Entry*)fn_6_8180(self->data->sub1C8, (void*)&buf);
    if (entry->flag == 0) {
        g_sndSystem->playSE((SndID)3, -1, 0, 0, -1);
        return;
    }
    if (entry->child == NULL) {
        out.len = 0;
        u32 slen;
        char* str;
        Message::getPrintIndexData(self->data->handle.getBuffer(), 0x3A, &str, &slen);
        u32 n = slen;
        int len = out.len;
        memcpy(out.text + len, str, n);
        int total = len + n;
        out.len = total;
        fn_6_535C(self, out.text, total);
    } else {
        self->data->state = 4;
        MuObject* obj = self->data->object;
        self->f44((int)obj->m_sceneModel);
        char* mdl = *(char**)((char*)obj + 8);
        int off = *(int*)(mdl + 0x3c);
        const char* src = off ? mdl + off : 0;
        Name n;
        n.s[0] = 0;
        strcat(n.s, src);
        Name n2 = n;
        strcat(n2.s, lbl_7_data_6CC);
        Name n3 = n2;
        sprintf(n3.s + strlen(n3.s), lbl_7_data_6C8, 0);
        Name n4 = n3;
        obj->changeNodeAnimNIf(n4.s);
    }
    g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
}