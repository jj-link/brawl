#pragma force_active on
class Class_80487298 {
public:
    virtual void fn_802CAD00(int);
    unsigned short m04;
    short m06;
};

extern "C" void fn_802CC8DC(char* self, Class_80487298* value, int index) {
    char* column = self + index * 4;
    char* row = self + (index << 5);
    int i = 0;
    do {
        if (value->m04 != 0) {
            value->m06++;
        }
        Class_80487298* old = *(Class_80487298**)(column + 0xC);
        if (old->m04 != 0) {
            if (--old->m06 == 0 && old != 0) {
                old->fn_802CAD00(1);
            }
        }
        *(Class_80487298**)(column + 0xC) = value;
        if (value->m04 != 0) {
            value->m06++;
        }
        old = *(Class_80487298**)(row + 0xC);
        if (old->m04 != 0) {
            if (--old->m06 == 0 && old != 0) {
                old->fn_802CAD00(1);
            }
        }
        i++;
        *(Class_80487298**)(row + 0xC) = value;
        column += 0x20;
        row += 4;
    } while (i < 8);
}
