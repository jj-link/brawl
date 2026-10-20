#pragma force_active on
extern "C" void* fn_27_2637E8(void* obj, unsigned long a, int b, int c);
extern "C" void fn_27_263750(void* p, unsigned long v);
extern "C" void fn_27_263464(void* p);

class grYakumono {
public:
    int disableYakumono(unsigned long a, unsigned long b);
};

int grYakumono::disableYakumono(unsigned long a, unsigned long b) {
    void* p = *(void**)((char*)this + 0x14c);
    if (p == 0) {
        return 0;
    }
    fn_27_2637E8(p, a, 3, 0);
    if ((int)b >= 0) {
        fn_27_263750(p, b);
    }
    fn_27_263464(p);
    return 1;
}
