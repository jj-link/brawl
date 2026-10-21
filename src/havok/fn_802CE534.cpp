#pragma force_active on

struct FnObj {
    void* unk0;
    unsigned short unk4;
    unsigned short unk6;
};

class Object {
public:
    virtual void slot0(int);
};

extern "C" {
int fn_802CD914();
void fn_802CD884(FnObj*);
void fn_802CD8A4(Object*);
extern const unsigned char lbl_8041037C[];
extern unsigned int lbl_80532688[];
}

extern "C" void fn_802CE534(void) {
    int v = fn_802CD914();
    lbl_80532688[0] = (unsigned int)(lbl_8041037C + 0x14);
    lbl_80532688[1] = (unsigned int)fn_802CD884;
    lbl_80532688[2] = (unsigned int)fn_802CD8A4;
    lbl_80532688[3] = (unsigned int)v;
}

__declspec(section ".ctors") extern void* const fn_802CE534_ctor = (void*)fn_802CE534;
