#pragma force_active on
class soModuleAccesser;
extern "C" {
void fn_100_C028(void*, soModuleAccesser*);
void fn_100_C648(short*, const short*);
int fn_100_C108(void*, short*, soModuleAccesser*);
}

struct CaptainSubState {
    unsigned char pad[5];
    unsigned char active : 1;
    unsigned char rest : 7;
    unsigned char suspended;
};

extern "C" void fn_100_C078(unsigned char* object, short* source, soModuleAccesser* accesser) {
    CaptainSubState* sub = reinterpret_cast<CaptainSubState*>(object + 0xc);
    if ((source[0] & 1) != 0) {
        bool active = sub->active;
        if (active == true && sub->suspended == 0) {
            fn_100_C028(sub, accesser);
        }
    }
    short local[4];
    fn_100_C648(local, source);
    fn_100_C108(object + 4, local, accesser);
}
