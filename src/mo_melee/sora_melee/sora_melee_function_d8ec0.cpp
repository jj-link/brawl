#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_50588(void*, int);

struct soEventUnit;
template <class T> struct soInstanceUnit {
    int a;
    int b;
};
template <class T, int N> struct soArrayVector {
    soInstanceUnit<T> data[N];
};

struct Pre {
    char pad[0x14];
};

template <class A> struct Base {
    char pad[0xc];
    A m_arr;
    ~Base() {
        __destroy_arr(&m_arr, fn_27_50588, 8, 0x13);
    }
};

template <class T, class A> struct soInstanceManagerSimpleEntity : public Pre, public Base<A> {
    ~soInstanceManagerSimpleEntity();
};

template <class T, class A>
soInstanceManagerSimpleEntity<T, A>::~soInstanceManagerSimpleEntity() {
}

template class soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >;
