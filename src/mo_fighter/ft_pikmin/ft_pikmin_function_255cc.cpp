#pragma force_active on
class wnPikminPikmin;

struct soArrayListEnumerator {
    soArrayListEnumerator(const soArrayListEnumerator&);

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
    virtual unsigned int isEmpty();

    soArrayListEnumerator getEnumerator();
};

typedef soArrayList<wnPikminPikmin*, 10> PikminList;

struct Fn113Owner {
    char pad_00[0x80];
    PikminList list80;
};

extern "C" {
void* fn_113_24AB8(const void*);
int fn_113_242C8(const void*);
void fn_113_1B238(wnPikminPikmin*, int);
void* fn_113_24210(const void*, short);
}

extern "C" void fn_113_255CC(Fn113Owner* self, int a, int b, int c) {
    if (self->list80.isEmpty() == 0) {
        soArrayListEnumerator it = self->list80.getEnumerator();
        int i = 0;
        while (it.index >= 0) {
            wnPikminPikmin* elem = *(wnPikminPikmin**)fn_113_24AB8(&it);
            if (b >= 0 && i >= b) {
                if (c == 0) {
                    break;
                }
                fn_113_1B238(elem, a == 0);
            } else {
                fn_113_1B238(elem, a);
            }
            fn_113_242C8(&it);
            ++i;
        }
        fn_113_24210(&it, 0);
    }
}
