#include <iostream>

class drob
{
private:
    int chisl;
    int znamen;

public:
    drob (): chisl(0), znamen(1) {};

    drob (int chisl_, int znamen_): chisl(chisl_), znamen(znamen_)
    {
        this->sokrashenie();
    };

    ~drob() {};

    auto sokrashenie () -> void
    {
        for (int i=2; i<=znamen; i++)
        {
            if (!(chisl%i) && !(znamen%i))
            {
                while (!(chisl%i) && !(znamen%i))
                {
                    chisl /= i;
                    znamen /= i;
                }
            }
        }
    }

    auto obratn () -> drob
    {
        drob rezult (znamen, chisl);
        return rezult;
    }

    auto otrizanie() -> void
    {
        chisl*=-1;
    }

    auto zel_chast() -> int
    {
        return chisl/znamen;
    }

    const auto operator*(const drob& vtoraya_drob) const -> drob
    {
        drob rezult(chisl*vtoraya_drob.chisl, znamen*vtoraya_drob.znamen);
        return rezult;
    }

    const auto operator*(const int& chislo) const -> drob
    {
        drob rezult(chisl*chislo, znamen);
        return rezult;
    }

    const auto operator/(const drob& vtoraya_drob) const -> drob
    {
        drob rezult(chisl*vtoraya_drob.znamen, znamen*vtoraya_drob.chisl);
        return rezult;
    }

    const auto operator/(const int& chislo) const -> drob
    {
        if (chislo == 0)
        {
            std::cout << "na 0 delit nelza!" << std::endl;
            return *this;
        }
        drob rezult (chisl, znamen*chislo);
        return rezult;
    }

    const auto operator+(const drob& vtoraya_drob) const -> drob
    {
        drob rezult (chisl*vtoraya_drob.znamen+vtoraya_drob.chisl*znamen, znamen*vtoraya_drob.znamen);
        return rezult;
    }

    friend auto operator<< (std::ostream &out, const drob& a) -> std::ostream&;

    /*
    auto vivod() -> void
    {
        std::cout<<chisl<<'/'<<znamen<<endl;
    }
*/

};

auto operator<< (std::ostream &out, const drob& a) -> std::ostream&
{
    if (a.znamen == 1) out << a.chisl << std::endl;
    else out << a.chisl << "/" << a.znamen << std::endl;
    return out;
}

    int main()
    {
        drob a(2,1);
        std::cout << a/0;
        std::cout << a;
    return 0;
    }
