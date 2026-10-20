#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" {

unsigned int randi__Fl(int);
void getFighterReStartPos__5StageFP5Vec3fi(void*, Vec3f*, int);
extern const float lbl_27_rodata_3958;

void getFighterReStartPos__7stMeleeFP5Vec3fi(void* thisp, Vec3f* startPos, unsigned int fighterIndex) {
    unsigned int* field = (unsigned int*)((char*)thisp + 0x1cc);
    if (fighterIndex == 0x1e) {
        unsigned int old = *field;
        unsigned int v;
        do {
            v = randi__Fl(4);
            *field = v;
        } while (v == old);
        getFighterReStartPos__5StageFP5Vec3fi(thisp, startPos, (int)v);
        startPos->y += lbl_27_rodata_3958;
    } else {
        getFighterReStartPos__5StageFP5Vec3fi(thisp, startPos, (int)fighterIndex);
    }
}

}
