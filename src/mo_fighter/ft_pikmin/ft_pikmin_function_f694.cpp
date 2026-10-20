#pragma force_active on
extern "C" {
void fn_113_F644(void* object, void* argument);
void fn_113_FD84(short* destination, const short* source);
void fn_113_F724(void* object, short* source, void* argument);
}

namespace {
struct Sub {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char rest : 7;
    unsigned char next;
    bool isEnabled() const { return enabled; }
};
}

extern "C" void fn_113_F694(void* object, const short* param, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    Sub* sub = reinterpret_cast<Sub*>(composite + 0xC);
    short local[4];
    if ((param[0] & 1) != 0 && sub->isEnabled() == true && sub->next == 0) {
        fn_113_F644(sub, argument);
    }
    fn_113_FD84(local, param);
    fn_113_F724(composite + 4, local, argument);
}
