#pragma force_active on

extern "C" {
extern char lbl_27_data_210B0[];
extern char lbl_27_data_5460[];
extern char lbl_27_data_18830[];

void fn_27_5057C(void*);
void fn_27_50588(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, int);
}

struct Array {
    void* vtable;
    void* vtable2;
    unsigned int bits;
    char elements[19 * 8];
};

struct Manager {
    void* vtable;
    unsigned char flag;
    void* secondary;
    unsigned char flag2;
    Array* array;
    Array storage;
};

template<class T> struct soInstanceUnit {};
template<class T, int N> struct soArrayVector {};

template<class T, class V>
struct soInstanceManagerSimpleEntity {
    soInstanceManagerSimpleEntity();
};

struct soEventUnit;

template<>
soInstanceManagerSimpleEntity<
    soEventUnit*,
    soArrayVector<soInstanceUnit<soEventUnit*>, 19>
>::soInstanceManagerSimpleEntity() {
    Manager* p = (Manager*)this;
    p->flag = 0;
    p->flag2 = 0;
    p->secondary = lbl_27_data_5460;
    p->array = &p->storage;
    p->vtable = lbl_27_data_18830;

    Array* a = &p->storage;
    a->vtable = lbl_27_data_210B0;
    a->vtable2 = lbl_27_data_210B0 + 0x48;
    a->bits &= 0x1FFF;

    __construct_array(a->elements, fn_27_5057C, fn_27_50588, 8, 19);
}
