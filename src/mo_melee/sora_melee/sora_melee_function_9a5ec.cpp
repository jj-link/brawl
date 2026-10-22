#pragma force_active on
struct Node {
    int unused;
    int value;
    char padding[5];
    signed char next;
    char padding2[2];
};
extern unsigned char lbl_27_data_14580[];
struct Iterator {
    virtual void slot0();
    virtual void slot1();
    virtual int next();
    unsigned char flag;
    Node* ptr;
    int index;
    Iterator() { flag = 0; *(void**)this = lbl_27_data_14580; ptr = 0; index = -1; }
    Iterator& operator=(const Iterator& other) {
        flag = other.flag;
        ptr = other.ptr;
        index = other.index;
        return *this;
    }
    Node* operator->() const { return &ptr[index]; }
    int advance() {
        if (!next()) {
            index = -1;
            return 0;
        }
        index = ptr[index].next;
        return 1;
    }
};
extern "C" Iterator fn_27_9EFA8(void*);
extern "C" void fn_27_9F284(void*, int);
struct List {
    Iterator begin() { return fn_27_9EFA8(this); }
    void erase(Iterator& it) { fn_27_9F284(this, it.index); }
};
struct Self {
    char pad[0x78];
    List list;
};
extern "C" int fn_27_9A5EC(Self* self, int value) {
    Iterator it;
    it = self->list.begin();
    do {
        if (value == it->value) {
            self->list.erase(it);
            return 1;
        }
    } while (it.advance());
    return 0;
}
