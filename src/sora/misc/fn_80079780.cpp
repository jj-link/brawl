#pragma force_active on
extern "C" {

class sndSystem;
extern sndSystem* g_sndSystem;
void fn_80075B7C(sndSystem*);

void fn_80079780(void) {
    fn_80075B7C(g_sndSystem);
}

}
