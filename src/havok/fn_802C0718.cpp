#pragma force_active on
extern "C" char lbl_80486EF8[];

class Class_802A0DC4 {
public:
    Class_802A0DC4() {}
    ~Class_802A0DC4() {}
};

struct Vtable_Class_802C0718 {
    void* vtable;
    Vtable_Class_802C0718() {}
};

struct ListNode {
    void* object;
    void* pad0;
    void* pad1;
    ListNode* next;
};

class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void* fn_80046A28();
};

class Class_802C0718 : public Class_802A0DC4, public Vtable_Class_802C0718 {
public:
    unsigned char m_04[2];
    unsigned short m_06;
    int m_08;
    ListNode* m_0C;
    ListNode* m_10;
    unsigned char m_14[8];
    void* m_1C;
    void* m_20;

    Class_802C0718(int, int, int);
};

class Class_802A1FD4 {
public:
    static void operator delete(void* p);
};

Class_802C0718::Class_802C0718(int arg0, int a1, int a2) {
    m_06 = 1;
    m_08 = a2;
    vtable = lbl_80486EF8;

    ListNode* cursor = (ListNode*)arg0;
    while (cursor->next != 0) {
        cursor = cursor->next;
    }
    m_0C = cursor;

    ListNode* tail = (ListNode*)a1;
    while (tail->next != 0) {
        tail = tail->next;
    }
    m_10 = tail;

    m_1C = ((Class_8042B6D0*)*((void**)arg0))->fn_80046A28();
    m_20 = ((Class_8042B6D0*)*((void**)a1))->fn_80046A28();
}