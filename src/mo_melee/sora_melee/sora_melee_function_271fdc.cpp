#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Vec2 {
    float x;
    float y;
};

struct Data {
    u32 a;
    float x;
    float y;
    u32 pad;
    u32 key;
};

struct Node {
    void* unk0;
    Node* next;
    Data* data;
};

struct List {
    void* unk0;
    Node* head;
    void* unk8;
    Node* cur;
    u32 count;
};

extern "C" void fn_27_2723D0(List* list, const Vec2* v, u32 key);

extern "C" void fn_27_271FDC(u8* base, const Vec2* v, u32 flag, u32 key) {
    if (flag == 0)
        fn_27_2723D0((List*)(base + 4), v, key);
    else
        fn_27_2723D0((List*)(base + 0x20), v, key);
}
