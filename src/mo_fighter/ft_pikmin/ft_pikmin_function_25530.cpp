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

extern "C" {
void* fn_113_24AB8(const void*);
int fn_113_242C8(const void*);
void fn_113_1B21C(wnPikminPikmin*, int);
void* fn_113_24210(const void*, short);
}

extern "C" void fn_113_25530(soArrayList<wnPikminPikmin*, 10>* self) {
    if (self->isEmpty() != 1) {
        soArrayListEnumerator it = self->getEnumerator();
        int i = 0;
        while (it.index >= 0) {
            wnPikminPikmin* elem =
                *(wnPikminPikmin**)fn_113_24AB8(&it);
            fn_113_242C8(&it);
            fn_113_1B21C(elem, 6 - i);
            ++i;
        }
        fn_113_24210(&it, 0);
    }
}
