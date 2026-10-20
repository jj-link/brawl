#pragma force_active on
class Yakumono
{
public:
    void setSituationKind(int kind);
};

class grYakumono
{
    char _pad[0x14c];
    Yakumono* m_yakumono;

public:
    void setSituationODD();
};

void grYakumono::setSituationODD()
{
    m_yakumono->setSituationKind(7);
}
