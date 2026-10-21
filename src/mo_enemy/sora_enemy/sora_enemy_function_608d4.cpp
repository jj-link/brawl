#pragma force_active on
extern "C" {
struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual short v7();
    virtual void v8();
    virtual void v9();
};

void fn_41_2D038(void* self, int idx, short v, void** p, void* tbl);
extern char lbl_41_data_3E50[];
extern char lbl_41_data_1B188[];

void* fn_41_608D4(void* self, void* owner) {
    *reinterpret_cast<char**>(self) = lbl_41_data_1B188;
    char* g = *reinterpret_cast<char**>(static_cast<char*>(owner) + 0xd8);
    void* d = *reinterpret_cast<void**>(g + 0xc0);
    struct Msg {
        int a;
        int b;
        void* self;
        void* data;
    } msg;
    msg.a = 1;
    msg.b = 0x37;
    msg.self = &msg.a;
    msg.data = d;
    Sub* s = *reinterpret_cast<Sub**>(*reinterpret_cast<char**>(static_cast<char*>(owner) + 0xd8) + 0x80);
    short v = reinterpret_cast<Sub*>(reinterpret_cast<char*>(s) + 8)->v7();
    fn_41_2D038(static_cast<char*>(self) + 4, 0, v, &msg.self, lbl_41_data_3E50);
    return self;
}
}
