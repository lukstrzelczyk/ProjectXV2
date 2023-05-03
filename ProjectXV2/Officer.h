#pragma once
#include "Csoldier.h"
class Officer :
    public Csoldier
{
    std::string commanded_unit{"Company A"};
public:
    Officer() = default;
    Officer(const Officer& clone);
    Officer(std::string cu, size_t _age, std::string _name, std::string _surname, std::string _rank, size_t num, size_t id);
    Officer(std::string cu);
    void promote_soldier(Csoldier& soldier);
    void introduce();
    void show();
    void printoperator(std::ostream& out)const;
    Officer& operator=(Officer& clone) {
        this->Csoldier::~Csoldier();
        this->Officer::Officer(clone);
    }
    static Officer* load(std::string text);

};

