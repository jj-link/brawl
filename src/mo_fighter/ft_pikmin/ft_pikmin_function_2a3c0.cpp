#pragma force_active on
extern "C" {
void fn_113_2A388(void*, void*);
void fn_113_2A458(short* destination, const short* source);
void fn_113_2A450(void* object, const short* source, void* argument);
}

struct Pikmin2Sub {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char other : 7;
    unsigned char disabled;
};

extern "C" void fn_113_2A3C0(void* object, const short* source, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    Pikmin2Sub* sub = reinterpret_cast<Pikmin2Sub*>(composite + 0xC);
    if ((*source & 1) != 0 && static_cast<bool>(sub->flag) == true && sub->disabled == 0) {
        fn_113_2A388(sub, argument);
    }

    short local;
    fn_113_2A458(&local, source);
    fn_113_2A450(composite + 4, &local, argument);
}
