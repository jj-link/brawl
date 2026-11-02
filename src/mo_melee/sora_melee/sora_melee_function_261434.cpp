#include <types.h>
#include <nw4r/g3d/g3d_resmdl.h>

#pragma force_active on

extern "C" nw4r::g3d::ResNode* GetResNode__Q34nw4r3g3d6ResMdlCFi(
    const nw4r::g3d::ResMdl*, int);
extern "C" void* fn_80110C78(void*, void*, unsigned long, unsigned long);

struct CollisionFlags {
    unsigned char b7 : 1;
    unsigned char b6 : 1;
    unsigned char b5 : 1;
    unsigned char b4 : 1;
    unsigned char b3 : 1;
    unsigned char b2 : 1;
    unsigned char b1 : 1;
    unsigned char b0 : 1;
};

class GroundBase {
public:
    char pad0[0x3C];
};

class Ground : public GroundBase {
public:
#define SLOT(n) virtual void slot##n();
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7)
    SLOT(8) SLOT(9) SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15)
    SLOT(16) SLOT(17) SLOT(18) SLOT(19) SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29) SLOT(30) SLOT(31)
    SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47)
    SLOT(48) SLOT(49) SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55)
#undef SLOT

    virtual int setNodeCollision(bool, unsigned long, unsigned long, bool);

    char pad40[4];
    void** m_models;
    char pad48[4];
    void* unk4C;
};

int Ground::setNodeCollision(
    bool arg0, unsigned long arg1, unsigned long arg2, bool arg3)
{
    if (arg3) {
        void* local = 0;
        void* model =
            *(void**)((char*)this->m_models + ((arg1 << 2) & 0x3FFFCu));
        if (!model)
            return 0;

        local = *(void**)((char*)model + 0xe8);
        if (!local)
            return 0;

        nw4r::g3d::ResNode* node =
            GetResNode__Q34nw4r3g3d6ResMdlCFi(
                (const nw4r::g3d::ResMdl*)&local, arg2);
        if (!node)
            return 0;

        int off1 = *(int*)((char*)node + 0x60);
        void* t1 = off1 ? (void*)((char*)node + off1) : 0;
        if (t1) {
            unsigned int r0;
            if (t1)
                r0 = *(unsigned int*)((char*)t1 + 0xc);
            else
                r0 = 0;
            this->setNodeCollision(
                arg0, arg1, (unsigned long)(r0 & 0xFFFF), arg3);
        }

        int off2 = *(int*)((char*)node + 0x64);
        void* t2 = off2 ? (void*)((char*)node + off2) : 0;
        if (t2) {
            unsigned int r0;
            if (t2)
                r0 = *(unsigned int*)((char*)t2 + 0xc);
            else
                r0 = 0;
            this->setNodeCollision(
                arg0, arg1, (unsigned long)(r0 & 0xFFFF), arg3);
        }
    }

    if (this->unk4C != 0) {
        void* r = fn_80110C78(this->unk4C, this, arg1, arg2);
        if (r) {
            unsigned char* p = (unsigned char*)r;
            p[0x56] |= 0x80;
            CollisionFlags* f = (CollisionFlags*)(p + 0x54);
            if (arg0) {
                f->b4 = 1;
                f->b6 = f->b4;
            } else {
                f->b7 = 0;
                f->b4 = f->b7;
                f->b6 = f->b4;
            }
            return 1;
        }
    }

    return 0;
}
