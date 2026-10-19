#pragma force_active on
class grYakumono {
public:
    ~grYakumono();
};

void operator delete(void* p);

extern "C" {
void __dt__10grYakumonoFv(grYakumono* self, short flag);

grYakumono* fn_60_68F0(grYakumono* self, int flag) {
    if (self != 0) {
        __dt__10grYakumonoFv(self, 0);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
