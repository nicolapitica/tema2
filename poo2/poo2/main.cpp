#include <iostream>
#include <vector>
#include <string>

class Transport
{
    public: 
        virtual double pasageri()=0;
        virtual double kilometri()=0;
        virtual ~Transport(){};
};

class Tramvai: public Transport
{
    private:
        int nrlinie, nrstatii;
        double distantastatii;
    public: 
        Tramvai()=default;
        Tramvai(int nrlinie, int nrstatii, double distantastatii)
        {
            this-> nrstatii=nrstatii;
            this-> nrlinie=nrlinie;
            this-> distantastatii=distantastatii;
        }
        int getNrlinie() const 
        {
            return nrlinie;
        }
        double kilometri() override
        {
            return nrstatii*distantastatii;
        }
        double pasageri() override
        {
            return kilometri()*40;
        }

};

class Troleibuz: public Transport
{
    private:
        int nrlinie, nrstatii;
        double distantastatii;
    public: 
        Troleibuz()=default;
        Troleibuz(int nrlinie, int nrstatii, double distantastatii)
        {
            this-> nrstatii=nrstatii;
            this-> nrlinie=nrlinie;
            this-> distantastatii=distantastatii;
        }
        int getNrlinie() const 
        {
            return nrlinie;
        }
        double kilometri() override
        {
            return nrstatii*distantastatii;
        }
        double pasageri() override
        {
            return kilometri()*25;
        }
};

class Autobuz: public Transport
{
    private:
        int nrlinie, nrstatii;
        double distantastatii;
    public: 
        Autobuz()=default;
        Autobuz(int nrlinie, int nrstatii, double distantastatii)
        {
            this-> nrstatii=nrstatii;
            this-> nrlinie=nrlinie;
            this-> distantastatii=distantastatii;
        }
        int getNrlinie() const 
        {
            return nrlinie;
        }
        double kilometri() override
        {
             return nrstatii*distantastatii;
        }
        double pasageri() override
        {
            return kilometri()*30;
        }
};

class Angajati
{
    protected:
        std::string nume;
    public:
        virtual double ore() =0;
};

class Vatman: public Angajati
{
    private:
        std::string nume;
        std::vector<int> linii;
        int nrlinii;
    public:
        Vatman(std::string nume,std::vector<int> linii, int nrlinii)
        {
            this->nume=nume;
            this-> linii= linii;
            this-> nrlinii=nrlinii;
        }
        std::string getNume() const 
        {
            return nume;
        }
        std::vector<int> getLinie() const
        {
            return linii;
        }
        double ore() override
        {
            return nrlinii*2;
        }
        void adaugaLinie(int linie) 
        {
            linii.push_back(linie);
            nrlinii++;
        }
        void afisare()
        {
            std::cout<<"Cele "<<nrlinii<<" linii pe care le-a operat "<<nume<<" azi sunt: ";
            for(int i=0; i<nrlinii-1;i++)
                std::cout<<linii[i]<<", ";
            std::cout<<linii[nrlinii-1]<<"."<<"\n";
            std::cout<<"A lucrat "<<ore()<<" ore."<<"\n";
        }
};

class Sofer: public Angajati
{
    private:
        std::string nume;
        std::vector<int> linii;
        int nrlinii;
    public:
        Sofer(std::string nume,std::vector<int> linii,int nrlinii)
        {
            this->nume=nume;
            this-> linii= linii;
            this-> nrlinii=nrlinii;
        }
        std::string getNume() const 
        {
        return nume;
        }
        std::vector<int> getLinie() const
        {
            return linii;
        }
        double ore() override
        {
            return nrlinii*3;
        }
        void adaugaLinie(int linie) 
        {
            linii.push_back(linie);
            nrlinii++;
        }
        void afisare()
        {
            std::cout<<"Cele "<<nrlinii<<" linii pe care le-a operat "<<nume<<" azi sunt: ";
            for(int i=0; i<nrlinii-1;i++)
                std::cout<<linii[i]<<", ";
            std::cout<<linii[nrlinii-1]<<"."<<"\n";
            std::cout<<"A lucrat "<<ore()<<" ore."<<"\n";
        }
};

class Controlor: public Angajati
{
    private:
        std::string nume;
        int nramenzi;
        std::vector<int> linii;
        int nrlinii;
    public:
        Controlor(std::string nume,int nramenzi,std::vector<int> linii,int nrlinii)
        {
            this->nume=nume;
            this-> nramenzi=nramenzi;
            this-> linii= linii;
            this-> nrlinii=nrlinii;
        }
        std::string getNume() const 
        {
            return nume;
        }
        int getAmenzi() const 
        {
            return nramenzi;
        }
        void cresteAmenzi(int nr) 
        {
            nramenzi += nr;
        }
        double ore() override
        {
            return nrlinii*0.5;
        }
        void adaugaLinie(int linie) 
        {
            linii.push_back(linie);
            nrlinii++;
        }
        void afisare()
        {
            std::cout<<"Cele "<<nrlinii<<" linii pe care le-a operat "<<nume<<" azi sunt: ";
            for(int i=0; i<nrlinii-1;i++)
                std::cout<<linii[i]<<", ";
            std::cout<<linii[nrlinii-1]<<"."<<"\n";
            std::cout<<"A lucrat "<<ore()<<" ore si a dat "<<nramenzi<<" amenzi."<<"\n";
        }
};

class STB
{
    private: 
        std::vector<Transport*> vehicule;
        std::vector<Angajati*> personal;
        Transport* cautaVehicul(int nrlinie) 
        {
            for (const auto& vehicul : vehicule) 
            {
                // Verificam daca se potriveste nr liniei
                if (Tramvai* tramvai = dynamic_cast<Tramvai*>(vehicul)) 
                {
                    if (tramvai->getNrlinie() == nrlinie) 
                        return tramvai;
                } 
                else if (Autobuz* autobuz = dynamic_cast<Autobuz*>(vehicul)) 
                {
                    if (autobuz->getNrlinie() == nrlinie) 
                        return autobuz;
                } 
                else if (Troleibuz* troleu = dynamic_cast<Troleibuz*>(vehicul)) 
                {
                    if (troleu->getNrlinie() == nrlinie) 
                        return troleu;
                }
            }
            return nullptr; // Daca nu avem linia deja pusa in circulatie.
        }
        void actualizeazaAngajat(std::string nume, int linie) 
        {
            int ok=0;
            for (Angajati* angajat : personal) 
            {
                if(Vatman* vatman = dynamic_cast<Vatman*>(angajat)) 
                {
                    if (vatman->getNume() == nume) 
                    {
                        ok=1;
                        if(cautaVehicul(linie)==nullptr)
                        {
                            int nrlinie, nrstatii;
                            double distantastatii;
                            std::cout << "Introduceti numarul de statii si distanta dintre statii: ";
                            std::cin>> nrstatii >> distantastatii;
                            vehicule.push_back(new Tramvai(linie, nrstatii, distantastatii));  
                            vatman->adaugaLinie(linie);
                            std::cout << "Acum circulati pe linia  " << linie << ".\n";
                            return; // Iesi din bucla cand gaseste angajatul si il actualizeaza.      
                        }
                        else
                        {
                            Transport* vehiculPtr = cautaVehicul(linie); 
                            // Verificam daca obiectul pointat e un tramvai.
                            Tramvai* tramvaiPtr = dynamic_cast<Tramvai*>(vehiculPtr);
                            if (tramvaiPtr) 
                            {
                                vatman->adaugaLinie(linie);
                                std::cout << "Acum circulati pe linia  " << linie << ".\n";
                                return;
                            }
                            else
                                std::cout<<"Linie gresita. Vatmanul poate conduce doar tramvaie."<<"\n";
                        }
                    }
                }
                else if(Sofer* sofer = dynamic_cast<Sofer*>(angajat)) 
                {
                    ok=1;
                    if (sofer->getNume() == nume) 
                    {
                        if(cautaVehicul(linie)==nullptr)
                        {
                            std::string tip;
                            int nrlinie, nrstatii;
                            double distantastatii;
                            std::cout << "Ce tip de vehicul este?(Autobuz sau Troleibuz): ";
                            std::cin.ignore();
                            getline(std::cin, tip);
                            std::cout << "Introduceti numarul de statii si distanta dintre statii: ";
                            std::cin >> nrstatii >> distantastatii;
                            if(tip=="Autobuz")
                            {
                                vehicule.push_back(new Autobuz(linie, nrstatii, distantastatii));
                                sofer->adaugaLinie(linie);
                                std::cout << "Acum circulati pe linia  " << linie << ".\n";
                                return;
                            }
                            else if(tip=="Troleibuz")
                            {
                                vehicule.push_back(new Troleibuz(linie, nrstatii, distantastatii));
                                sofer->adaugaLinie(linie);
                                std::cout << "Acum circulati pe linia  " << linie << ".\n";
                                return;
                            }     
                        }
                        else
                        {
                            Transport* vehiculPtr = cautaVehicul(linie); 
                            // Verificam daca obiectul pointat e un autobuz sau troleibuz.
                            Autobuz* autobuzPtr = dynamic_cast<Autobuz*>(vehiculPtr);
                            Troleibuz* troleuPtr = dynamic_cast<Troleibuz*>(vehiculPtr);
                            if(autobuzPtr || troleuPtr) 
                            {
                                sofer->adaugaLinie(linie);
                                std::cout << "Acum circulati pe linia  " << linie << ".\n";
                                return;
                            }
                            else
                                std::cout<<"Linie gresita. Soferul poate conduce doar autobuze sau troleibuze."<<"\n";

                        }
                    }
                }
                else if(Controlor* controlor = dynamic_cast<Controlor*>(angajat)) 
                {
                    ok=1;
                    if (controlor->getNume() == nume) 
                    {
                        if(cautaVehicul(linie)==nullptr)
                        {
                            std::cout<<"Linia nu se afla in circulatie."<<"\n";
                        }
                        else
                        {
                            controlor->adaugaLinie(linie);
                            std::cout << "Acum operati pe linia  " << linie << ".\n";
                            return; 
                        }
                    }
                }
            }
            if(ok==0)
                std::cout << "Nu s-a gasit niciun angajat cu numele dat.\n";
        }
        double salariu(Angajati *ang) const
        {
            Vatman *vatman;
            Sofer *sofer;
            Controlor *controlor;
            double suma = 0.0;
            if((vatman = dynamic_cast<Vatman*>(ang)) != nullptr)
            {
                for (int linie : vatman->getLinie()) 
                {
                    for (Transport* vehicul : vehicule) 
                    {
                        if (Tramvai* tramvai = dynamic_cast<Tramvai*>(vehicul)) 
                        {
                            if (tramvai->getNrlinie() == linie) 
                            suma += tramvai->kilometri()*0.75;
                        }
                    }
                }
            }
            else if((sofer = dynamic_cast<Sofer*>(ang)) != nullptr)
            {
                for (int linie : sofer->getLinie()) 
                {
                    for (Transport* vehicul : vehicule) 
                    {
                        if (Autobuz* autobuz = dynamic_cast<Autobuz*>(vehicul)) 
                        {
                            if (autobuz->getNrlinie() == linie) 
                            suma += autobuz->kilometri()*0.95;
                        }
                        else if (Troleibuz* troleu = dynamic_cast<Troleibuz*>(vehicul)) 
                        {
                            if (troleu->getNrlinie() == linie) 
                                suma += troleu->kilometri()*0.95;
                        }
                    }
                }
            }
            else if((controlor = dynamic_cast<Controlor*>(ang)) != nullptr)
            {
                suma=controlor->getAmenzi()*0.35;
            }
            else
                std::cout<<"Angajat necunoscut.";
            return suma;
        }
        
    public:
        void adaugaVatman(const std::string& nume, const std::vector<int>& linii, int nrlinii) 
        {
            personal.push_back(new Vatman(nume, linii, nrlinii));
            std::cout << "Noul vatman a fost adaugat." << '\n';
        }

        void adaugaSofer(const std::string& nume, const std::vector<int>& linii, int nrlinii) 
        {
            personal.push_back(new Sofer(nume, linii, nrlinii));
            std::cout << "Noul sofer a fost adaugat." << '\n';
        }

        void adaugaControlor(const std::string& nume, int nramenzi, const std::vector<int>& linii, int nrlinii) 
        {
            personal.push_back(new Controlor(nume, nramenzi, linii, nrlinii));
            std::cout << "Noul controlor a fost adaugat." << '\n';
        }

        ~STB() 
        {
            for (auto& angajat : personal) 
            {
                delete angajat;
            }
            for (auto& vehicle : vehicule) 
            {
                delete vehicle;
            }
        }
        
        void afisareSalariu()
        {
            std::string nume;
            std::cout<<"Salariul carui angajat vreti sa il aflati?: "<<"\n";
            getline(std::cin, nume);
            int ok=0;
            for (Angajati* angajat : personal) 
            {
                if(Vatman* vatman = dynamic_cast<Vatman*>(angajat)) 
                {
                    ok=1;
                    if (vatman->getNume() == nume) 
                    {
                        std::cout<<"Salariul angajatului "<<nume<<" de azi este "<< salariu(vatman)<<" lei."<<"\n";
                    }
                }
                else if(Sofer* sofer = dynamic_cast<Sofer*>(angajat)) 
                {
                    ok=1;
                    if (sofer->getNume() == nume) 
                    {
                        std::cout<<"Salariul angajatului "<<nume<<" de azi este "<< salariu(sofer)<<" lei."<<"\n";
                    }
                }
                else if(Controlor* controlor = dynamic_cast<Controlor*>(angajat)) 
                {
                    ok=1;
                    if (controlor->getNume() == nume) 
                    {
                        std::cout<<"Salariul angajatului "<<nume<<" de azi este "<< salariu(controlor)<<" lei."<<"\n";
                    }
                }
                if(ok==0)
                    std::cout << "Nu s-a gasit niciun angajat cu numele dat."<<"\n";
            }
        }

        void amenda()
        {
            int nr, ok=1;
            std::string nume;
            std::cout<<"Cum va numiti?: ";
            getline(std::cin, nume);
            for (Angajati* angajat : personal) 
            {
                if(Controlor* controlor = dynamic_cast<Controlor*>(angajat)) 
                {
                    if (controlor->getNume() == nume) 
                    {
                        std::cout<<"Cate amenzi ati dat pe linia pe care ati operat?: ";
                        std::cin>>nr;
                        controlor->cresteAmenzi(nr);
                        ok=0;
                        std::cout<<"Amenzile au fost inregistrate."<<"\n";
                    }
                }
            }
            if(ok==1)
                std::cout << "Nu s-a gasit niciun angajat cu numele dat."<<"\n";
        }

        friend std::istream& citireangajat(std::istream& is, STB& stb);
        friend std::istream& actualizarereangajat(std::istream& is, STB& stb);

        friend std::ostream& afisareVehicule(std::ostream& os, const STB& stb);
        friend std::ostream& afisarePersonal(std::ostream& os, const STB& stb);
};

std::istream& citireangajat(std::istream& is, STB& stb)
{   //Functia de citire a angajatilor.
    std::string numeAngajat, post;
    int linie;
    std::cout << "Cum va numiti?: ";
    getline(is, numeAngajat);
    std::cout << "Ce post aveti?(Vatman, Sofer sau Controlor): ";
    getline(is, post);
    if(post == "Vatman")
    {
        std::vector<int> linii;
        std::cout << "Introduceti numarul liniei pe care o sa circulati: ";
        is>>linie;
        if(stb.cautaVehicul(linie)==nullptr)
        {
            int nrlinie, nrstatii;
            double distantastatii;
            std::cout << "Introduceti numarul de statii si distanta dintre statii: ";
            is >> nrstatii >> distantastatii;
            stb.vehicule.push_back(new Tramvai(linie, nrstatii, distantastatii));
            linii.push_back(linie);
            stb.adaugaVatman(numeAngajat, linii, 1);
        }
        else
        {
            Transport* vehiculPtr = stb.cautaVehicul(linie); 
            // Verificam daca obiectul pointat e un tramvai.
            Tramvai* tramvaiPtr = dynamic_cast<Tramvai*>(vehiculPtr);
            if (tramvaiPtr) 
            {
            // Daca obiectul este un Tramvai, apelam adaugaVatman
                linii.push_back(linie);
                stb.adaugaVatman(numeAngajat, linii, 1);
            }
            else
                std::cout<<"Linie gresita. Vatmanul poate conduce doar tramvaie.";
        }
    } 
    else if (post == "Sofer") 
    {
        std::vector<int> linii;
        std::string tip;
        std::cout << "Ce tip de vehicul doriti sa conduceti?(Autobuz sau Troleibuz): ";
        getline(is, tip);
        std::cout << "Introduceti numarul liniei pe care o sa circulati: ";
        is >> linie;
        if(stb.cautaVehicul(linie)==nullptr)
        {
            int nrlinie, nrstatii;
            double distantastatii;
            std::cout << "Introduceti numarul de statii si distanta dintre statii: ";
            is >> nrstatii >> distantastatii;
            if(tip=="Autobuz")
            {
                //Autobuz* autobuz= new Autobuz(linii[0], nrstatii, distantastatii);
                stb.vehicule.push_back(new Autobuz(linie, nrstatii, distantastatii));
                linii.push_back(linie);
                stb.adaugaSofer(numeAngajat, linii, 1);
            }
            else
            {
                //Troleibuz* troleu= new Troleibuz(linii[0], nrstatii, distantastatii);
                stb.vehicule.push_back(new Troleibuz(linie, nrstatii, distantastatii));
                linii.push_back(linie);
                stb.adaugaSofer(numeAngajat, linii, 1);
            }
        }
        else
        {
            Transport* vehiculPtr = stb.cautaVehicul(linie); 
            // Verificam daca obiectul pointat e un tramvai.
            Autobuz* autobuzPtr = dynamic_cast<Autobuz*>(vehiculPtr);
            Troleibuz* troleuPtr = dynamic_cast<Troleibuz*>(vehiculPtr);
            if (autobuzPtr || troleuPtr) 
            {
            // Daca obiectul este un Autobuz sau Troleibuz, apelam adaugaSofer
                linii.push_back(linie);
                stb.adaugaSofer(numeAngajat, linii, 1);
            }
            else
                std::cout<<"Linie gresita. Soferul poate conduce doar autobuze sau troleibuze.";
        }
    } 
    else if (post == "Controlor") 
    {
        std::vector<int> linii;
        std::cout << "Introduceti numarul liniei pe care veti opera: ";
        is >> linie;
        if(stb.cautaVehicul(linie)==nullptr)
        {
            std::cout<<"Linia nu se afla in circulatie."<<"\n";
        }
        else
        {
            linii.push_back(linie);
            stb.adaugaControlor(numeAngajat, 0, linii, 1);
        }
    } 
    else 
    {
        std::cout << "Postul introdus este invalid.";
    }
    return is;
}

std::istream& actualizarereangajat(std::istream& is, STB& stb)
{   
    std::string numeAngajat;
    std::cout << "Cum va numiti?: ";
    getline(is, numeAngajat);
    std::cout << "Ce linie vreti sa operati?: ";
    int nrlinie;
    is >> nrlinie;
    stb.actualizeazaAngajat(numeAngajat,nrlinie);
    return is;
}
std::ostream& afisareVehicule(std::ostream& os, const STB& stb)
{   
    os << "Informatiile despre vehiculele care au fost puse in circulatie astazi. " << std::endl;
    for (const auto& vehicul : stb.vehicule) 
            {
                if (Tramvai* tramvai = dynamic_cast<Tramvai*>(vehicul)) 
                {
                    os<<"Traseul tramvaiul "<<tramvai->getNrlinie()<<" are o lungime de "<<tramvai->kilometri()<<" km si o medie de calatori de "<<tramvai->pasageri()<<" persoane,"<<" care au generat un castig de "<<tramvai->pasageri()*2.5<<" lei/pe cursa. (pretul calatoriei=2.50 lei)" <<"\n";
                } 
                else if (Autobuz* autobuz = dynamic_cast<Autobuz*>(vehicul)) 
                {
                    os<<"Traseul autobuzului "<<autobuz->getNrlinie()<<" are o lungime de "<<autobuz->kilometri()<<" km si o medie de calatori de "<<autobuz->pasageri()<<" persoane,"<<" care au generat un castig de "<<autobuz->pasageri()*3<<" lei/pe cursa. (pretul calatoriei=3.00 lei)" <<"\n";
                } 
                else if (Troleibuz* troleu = dynamic_cast<Troleibuz*>(vehicul)) 
                {
                    os<<"Traseul troleibuzului "<<troleu->getNrlinie()<<" are o lungime de "<<troleu->kilometri()<<" km si o medie de calatori de "<<troleu->pasageri()<<" persoane,"<<" care au generat un castig de "<<troleu->pasageri()*2.15<<" lei/pe cursa. (pretul calatoriei=2.15 lei)" <<"\n";
                }
            }
    return os;
}
std::ostream& afisarePersonal(std::ostream& os, const STB& stb)
{   
    os << "Informatiile despre angajatii care au lucrat astazi. " << std::endl;
    for(const auto& ang: stb.personal)
    {
        Vatman *vatman;
        Sofer *sofer;
        Controlor *controlor;
        if((vatman = dynamic_cast<Vatman*>(ang)) != nullptr)
        {
            vatman->afisare();
            os<<"Salariul lui "<<vatman->getNume()<<": "<<stb.salariu(vatman)<< " lei."<<"\n";
        }
        else if((sofer = dynamic_cast<Sofer*>(ang)) != nullptr)
        {
            sofer->afisare();
            os<<"Salariul lui "<<sofer->getNume()<<": "<<stb.salariu(sofer)<< " lei."<<"\n";
        }
        else if((controlor = dynamic_cast<Controlor*>(ang)) != nullptr)
        {
            controlor->afisare();
            os<<"Salariul lui "<<controlor->getNume()<<": "<<stb.salariu(controlor)<< " lei."<<"\n";
        }
    }
    return os;
}

int main()
{
    STB stb;
    // Tramvai tramvai(21,10,2);
    // Tramvai tramvai1(41,40,1.5);
    // std::vector<int> linii={21,41,36};
    // Controlor controlor("Gabi",47,linii,3);
    // Vatman vatman("Ion",linii,3,tramvai);
    std::cout<<"Buna ziua! Bine ati venit la Societatea de Transport Bucuresti!"<<'\n';
    
    int ok=1;
    while(ok==1) //Cat timp nu am selectat comanda 6 care inchide farmacia, aleg cate o comanda.
    {
        std::cout<<"Alegeti una din urmatoarele comenzi:"<<std::endl;
        std::cout<<"   1. Logare noua"<<std::endl;
        std::cout<<"   2. Actualizare angajat"<<std::endl;
        std::cout<<"   3. Aflarea salariului unui angajat"<<std::endl;
        std::cout<<"   4. Suprataxa"<<std::endl;
        std::cout<<"   5. Afisarea informatiilor despre vehicule"<<std::endl;
        std::cout<<"   6. Afisarea informatiilor despre personal"<<std::endl;
        std::cout<<"   7. Final de zi. Inchide sistemul"<<std::endl;
        int nr;
        std::cin>> nr;
        std::cin.ignore();
        switch(nr)
        {
            case 1:
                citireangajat(std::cin,stb);
                break;
            case 2:
                actualizarereangajat(std::cin, stb);
                break;
            case 3:
                stb.afisareSalariu();
                break;
            case 4:
                stb.amenda();
                break;
            case 5:
                afisareVehicule(std::cout,stb);
                break;
            case 6:
                afisarePersonal(std::cout,stb);
                break;
            default:
                std::cout<<"Sistemul s-a inchis.";
                ok=0;
        }
    }
    return 0;
}