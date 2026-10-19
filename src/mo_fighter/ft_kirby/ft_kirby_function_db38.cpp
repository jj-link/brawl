#pragma force_active on
extern "C" {

void fn_96_1DD1C(char*);
void fn_27_6678(void*, void*, void*, void*);

void fn_96_DB38(void* a, void* b, void* c, void* d) {
    void* self = a;
    void* p1 = b;
    void* p2 = c;
    void* p3 = d;
    unsigned long base;
    char* data;
    base = reinterpret_cast<unsigned long>(a);
    base += 0x20000;
    base -= 0x48d4;
    data = reinterpret_cast<char*>(base);
    fn_96_1DD1C(data);
    fn_27_6678(self, p1, p2, p3);
}

}
