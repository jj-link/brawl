#pragma force_active on
class wnPikminPikmin {
public:
    char pad[0x28];
    unsigned int unk28;
};

template <class T, class S>
class soArrayListEnumerator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual T* get();
    char pad[0x10 - 4];
};

typedef soArrayListEnumerator<wnPikminPikmin*, signed char> Enum;

template <class T, int N>
class soArrayList {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual int isEmpty();
    Enum getEnumerator();
    void erase(const Enum& it);
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
int fn_113_242C8(void* it);
}

extern "C" void fn_113_23FD8(Fn113Owner* self, unsigned int arg1) {
    char it[0x10];

    fn_113_241EC(&it);
    if (self->isEmpty() == 0) {
        const Enum& tmp = self->getEnumerator();
        fn_113_242AC(&it, &tmp);
        fn_113_24210(&tmp, 0);
        do {
            wnPikminPikmin* elem = *((Enum*)&it)->get();
            if (arg1 == elem->unk28) {
                self->erase(*(Enum*)&it);
                fn_113_24210(&it, 0);
                return;
            }
        } while (fn_113_242C8(&it) != 0);
    }

    if (self->m_list80.isEmpty() == 0) {
        const Enum& tmp = self->m_list80.getEnumerator();
        fn_113_242AC(&it, &tmp);
        fn_113_24210(&tmp, 0);
        do {
            wnPikminPikmin* elem = *((Enum*)&it)->get();
            if (arg1 == elem->unk28) {
                self->m_list80.erase(*(Enum*)&it);
                fn_113_24210(&it, 0);
                return;
            }
        } while (fn_113_242C8(&it) != 0);
    }

    if (self->m_list100.isEmpty() == 0) {
        const Enum& tmp = self->m_list100.getEnumerator();
        fn_113_242AC(&it, &tmp);
        fn_113_24210(&tmp, 0);
        do {
            wnPikminPikmin* elem = *((Enum*)&it)->get();
            if (arg1 == elem->unk28) {
                self->m_list100.erase(*(Enum*)&it);
                fn_113_24210(&it, 0);
                return;
            }
        } while (fn_113_242C8(&it) != 0);
    }

    fn_113_24210(&it, 0);
}
