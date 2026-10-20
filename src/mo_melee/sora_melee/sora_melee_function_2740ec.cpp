#pragma force_active on
class grYakumono {
public:
    virtual ~grYakumono();
};

// Pure virtual destructor: keeps the class from emitting a vtable in this file
// (the vtable is defined elsewhere in the game), while the out-of-line body
// still produces __dt__17grGimmickWarpZoneFv.
class grGimmickWarpZone : public grYakumono {
public:
    virtual ~grGimmickWarpZone() = 0;
};

grGimmickWarpZone::~grGimmickWarpZone() { }
