#pragma force_active on

class wnPikminPikmin;

template <class T, int N>
class soArrayList {
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
    virtual int capacity();

    unsigned int count : 5;
    unsigned int first : 10;
    unsigned int other : 5;
    unsigned int rest : 12;

    struct Node {
        unsigned char used : 1;
        unsigned char flags : 7;
        T value;
        signed char prev;
        signed char next;

        void reset() { used = 0; }
        void setNext(int n) { next = n; }
    };

    Node nodes[N];

    void clear();
};

template <class T, int N>
void soArrayList<T, N>::clear() {
    count = 0;
    first = -1;
    other = 0;

    if (capacity() == 1) {
        nodes[0].prev = -1;
        nodes[0].next = -1;
        nodes[0].reset();
    } else {
        for (int i = 0; i < capacity(); ++i) {
            nodes[i].prev = i - 1;
            nodes[i].next = i + 1;
            nodes[i].reset();
        }
        nodes[capacity() - 1].setNext(-1);
    }
}

template void soArrayList<wnPikminPikmin*, 10>::clear();
