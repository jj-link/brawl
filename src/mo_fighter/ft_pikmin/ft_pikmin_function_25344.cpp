#pragma force_active on
class wnPikminPikmin {
public:
    char pad_00[0x28];
    unsigned int m_28;
};

struct soArrayListEnumerator {
    void* a;
    void* b;
    int c;
    int index;
};

template <class T, int N>
class soArrayList {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual int isEmpty();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10(wnPikminPikmin**);
    virtual void vf11();
    virtual void vf12(int);
    
    soArrayListEnumerator getEnumerator();
};

typedef soArrayList<wnPikminPikmin*, 10> PikminList;

struct Fn113Owner : PikminList {
    char pad_04[0x80 - sizeof(PikminList)];
    PikminList m_list80;
    char pad_84[0x100 - 0x80 - sizeof(PikminList)];
    PikminList m_list100;
};

extern "C" {
void fn_113_241EC(void* it);
void fn_113_242AC(void* dst, const void* src);
void* fn_113_24210(const void* ptr, short count);
void* fn_113_24AB8(void* it);
int fn_113_242C8(void* it);
void fn_113_25530(Fn113Owner* self);
}

extern "C" void fn_113_25344(Fn113Owner* self, unsigned int arg1)
{
    soArrayListEnumerator it;
    
    fn_113_241EC(&it);
    if (self->isEmpty() == 0) {
        const soArrayListEnumerator& tmp = self->getEnumerator();
        fn_113_242AC(&it, &tmp);
        fn_113_24210(&tmp, 0);
        int i = 0;
        while (it.index >= 0) {
            wnPikminPikmin* elem = *(wnPikminPikmin**)fn_113_24AB8(&it);
            fn_113_242C8(&it);
            if (arg1 == elem->m_28) {
                self->m_list80.vf10(&elem);
                self->vf12(i);
                fn_113_25530(self);
                fn_113_24210(&it, 0);
                return;
            }
            ++i;
        }
    }
    if (self->m_list100.isEmpty() == 0) {
        const soArrayListEnumerator& tmp = self->m_list100.getEnumerator();
        fn_113_242AC(&it, &tmp);
        fn_113_24210(&tmp, 0);
        int i = 0;
        while (it.index >= 0) {
            wnPikminPikmin* elem = *(wnPikminPikmin**)fn_113_24AB8(&it);
            fn_113_242C8(&it);
            if (arg1 == elem->m_28) {
                self->m_list80.vf10(&elem);
                self->m_list100.vf12(i);
                fn_113_25530(self);
                fn_113_24210(&it, 0);
                return;
            }
            ++i;
        }
    }
    fn_113_24210(&it, 0);
}
