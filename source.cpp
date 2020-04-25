#include <iostream>

class drob
{
private:
    int chisl;
    int znamen;

    auto sokrashenie () -> void
    {
        if (chisl < 0 && znamen < 0)      //проверяем, не случилось ли такой ситуации, что и в чсл и в знм отриц число
        {
            chisl*=-1;
            znamen*=-1;
        }
        for (int i=2; i<=znamen; i++)                    //начинаем с 2, т.к. проверять делимость на 1 бессмысленно
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

public:
    drob (): chisl(0), znamen(1) {}; //конструктор по умолчанию, нужен для того, чтобы программа знала, что ей
                                                        //делать, когда объект типа drob создается без параметров

    drob (int chisl_, int znamen_): chisl(chisl_), znamen(znamen_) //пользовательский конструктор, нужен для
    {                                                                       //создания дробей
        this->sokrashenie();                                   // this (англ. "это"), используется для того, чтобы
    };                                                                      //находясь внутри объекта использовать
                                                                            //метод класса на самого себя
    ~drob() {};                                                 //деструктор, нужен для очистки памяти после удаления
                                                                            // объекта

    auto obratn () -> drob
    {
        //drob rezult (znamen, chisl);
        return drob(znamen,chisl);           //!!!!!!!!!!!!!!!!!!!!!!!!!!
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
        //drob rezult(chisl*vtoraya_drob.chisl, znamen*vtoraya_drob.znamen);
        return drob(chisl*vtoraya_drob.chisl, znamen*vtoraya_drob.znamen); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }

    const auto operator*(const int& chislo) const -> drob
    {
        //drob rezult(chisl*chislo, znamen);
        return drob(chisl*chislo, znamen);                                   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }

    const auto operator/(const drob& vtoraya_drob) const -> drob
    {
        if (vtoraya_drob.chisl == 0)                                //проверяем деление на ноль
        {
            std::cout << "na 0 delit nelza!" << std::endl;
            return *this;                                           //возвращаем делимое, тк операция деления не была
                                                                                    //совершена
        }
        //drob rezult(chisl*vtoraya_drob.znamen, znamen*vtoraya_drob.chisl);
        return drob(chisl*vtoraya_drob.znamen, znamen*vtoraya_drob.chisl); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }

    const auto operator/(const int& chislo) const -> drob
    {
        if (chislo == 0)
        {
            std::cout << "na 0 delit nelza!" << std::endl;
            return *this;                       //this - указатель на самого себя, его необходимо разыменовать, поэтому
                                                                    //добавляется *
        }
        //drob rezult (chisl, znamen*chislo);
        return drob(chisl, znamen*chislo);                                //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }

    const auto operator+(const drob& vtoraya_drob) const -> drob
    {
        //drob rezult (chisl*vtoraya_drob.znamen+vtoraya_drob.chisl*znamen, znamen*vtoraya_drob.znamen);
        return drob(chisl*vtoraya_drob.znamen+vtoraya_drob.chisl*znamen, znamen*vtoraya_drob.znamen); //!!!!!!!!!!!!!!
    }

    friend auto operator<< (std::ostream &out, const drob& a) -> std::ostream&; //объявляем перегрузку оператора вывода
                                                            //дружественной функцией, т.к. она определяется
                                                            //за пределами класса

    /*
    auto vivod() -> void
    {
        std::cout<<chisl<<'/'<<znamen<<endl;
    }
    */

    auto vivod_smesh () -> void
    {
        if (this->zel_chast() == 0) //если целая часть равна 0, то используем обычный вывод
        {
            std::cout << *this;
            return;                //завершаем функцию
        }
        if (chisl-(this->zel_chast()*znamen) == 0) //если числитель после выделения целой части равен нулю,
                                                                            // то выводим только целую часть
        {
            std::cout << this->zel_chast() << std::endl;
            return;                //завершаем функцию
        }
        std::cout << this->zel_chast() << "    " << chisl-(this->zel_chast()*znamen) << '/' << znamen << std::endl;
    }

    auto vivod_desyat () -> void
    {
        std::cout << double(chisl)/double(znamen) << std::endl;
    }

};

auto operator<< (std::ostream &out, const drob& a) -> std::ostream& //перегружаем оператор вывода
{
    if (a.znamen == 1) out << a.chisl << std::endl;
    else out << a.chisl << "/" << a.znamen << std::endl;
    return out;
}

int main(int argc, char* argv[])
{
    drob a(2,1);
    drob b(7,2);
    drob c(10,4);
    drob d(1,2);
    a.vivod_smesh();
    b.vivod_smesh();
    c.vivod_smesh();
    d.vivod_smesh();
    c.vivod_desyat();
    drob e(-5,-7);
    std::cout << e;
    return 0;
}
