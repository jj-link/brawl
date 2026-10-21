#pragma force_active on
// main/fn_8007979C.cpp

extern "C" {

class sndSystem;

extern sndSystem* g_sndSystem;
extern void fn_80076674(sndSystem*);

void fn_8007979C() {
    fn_80076674(g_sndSystem);
}

}
