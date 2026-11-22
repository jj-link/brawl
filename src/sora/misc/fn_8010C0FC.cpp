#pragma force_active on
#include <types.h>
#include <mu/mu_object.h>

extern "C" {
int sprintf(char*, const char*, ...);
int atoi(const char*);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);

extern const char lbl_8059E664;
extern const char lbl_8059E66C;
extern const char lbl_8059E670;
}

class Iface {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void slot13(void*);
};

extern Iface* lbl_805A033C;

struct Owner {
    char pad0[4];
    MuObject* obj4;
    MuObject* objs[84];
    Iface* scn;
    char pad1[0x361 - 0x15C];
    unsigned char flag;
};

inline void reverseCopy(char* dst, const char* src, unsigned int count, unsigned int last) {
    unsigned int i = 0;
    while (i < count)
        *dst++ = src[last - i++];
}

extern "C" void fn_8010C0FC(Owner* self, unsigned int arg1) {
    if (self->flag != 0) {
        MuObject* obj;
        MuObject** objects;
        MuObject** output;
        char* digits;
        char spC[6] = {0};
        char sp20[10] = {0};
        char sp8[2] = {0};
        MuObject* sp2C[9];
        Iface* scn = self->scn;
        unsigned int count;
        obj = self->obj4;
        char sp14[10] = {0};
        int n;
        unsigned int i;

        lbl_805A033C->slot13(scn);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
            lbl_805A033C, scn, (char*)&lbl_8059E664);

        n = sprintf(sp20, (const char*)&lbl_8059E66C, arg1);
        count = n;
        if (n == 0)
            count = 1;
        if (count > 9)
            count = 9;

        reverseCopy(sp14, sp20, count, count - 1);

        obj->setFrameNode((float)count);
        obj->setFrameVisible((float)count);

        objects = self->objs;
        output = sp2C;
        digits = sp14;
        for (i = 0; i < count; i++) {
            *output = *objects;
            sprintf(spC, (const char*)&lbl_8059E670, i);
            scn->slot13((*output)->m_sceneModel);
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
                scn, (*output)->m_sceneModel, spC);
            sp8[0] = *digits;
            (*output)->setFrameTex((float)atoi(sp8));
            ++objects;
            ++output;
            ++digits;
        }
    }
}
