#pragma force_active on
class StageObject;
class wnPikminPikmin;

class soExternalValueAccesser {
public:
    static int getWorkInt(StageObject* obj, unsigned long flag);
};

struct soArrayListEnumerator {
    char pad[0x10];
};

template <class T, int N>
class soArrayList {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual int isEmpty();
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
}

extern "C" int fn_113_2512C(Fn113Owner* self) {
    soArrayListEnumerator it;

    fn_113_241EC(&it);
    if (self->isEmpty() == 0) {
        const soArrayListEnumerator& tmp = self->getEnumerator();
        fn_113_242AC(&it, &tmp);
        fn_113_24210(&tmp, 0);
        do {
            wnPikminPikmin* elem = *(wnPikminPikmin**)fn_113_24AB8(&it);
            if (soExternalValueAccesser::getWorkInt((StageObject*)elem, 0x10000008) != 2) {
                fn_113_24210(&it, 0);
                return 0;
            }
        } while (fn_113_242C8(&it) != 0);
    }

    if (self->m_list80.isEmpty() == 0) {
        const soArrayListEnumerator& tmp = self->m_list80.getEnumerator();
        fn_113_242AC(&it, &tmp);
        fn_113_24210(&tmp, 0);
        do {
            wnPikminPikmin* elem = *(wnPikminPikmin**)fn_113_24AB8(&it);
            if (soExternalValueAccesser::getWorkInt((StageObject*)elem, 0x10000008) != 2) {
                fn_113_24210(&it, 0);
                return 0;
            }
        } while (fn_113_242C8(&it) != 0);
    }

    if (self->m_list100.isEmpty() == 0) {
        const soArrayListEnumerator& tmp = self->m_list100.getEnumerator();
        fn_113_242AC(&it, &tmp);
        fn_113_24210(&tmp, 0);
        do {
            wnPikminPikmin* elem = *(wnPikminPikmin**)fn_113_24AB8(&it);
            if (soExternalValueAccesser::getWorkInt((StageObject*)elem, 0x10000008) != 2) {
                fn_113_24210(&it, 0);
                return 0;
            }
        } while (fn_113_242C8(&it) != 0);
    }

    fn_113_24210(&it, 0);
    return 1;
}
