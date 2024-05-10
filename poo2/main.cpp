#include <iostream>
#include <vector>
#include <string>

class STB;

class Transport
{
    public: 
        virtual double incasari(int nrpasageri)=0;
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
        Tramvai(int nrlinie, int nrstatii, double distantastatii){
            this-> nrstatii=nrstatii;
            this-> nrlinie=nrlinie;
            this-> distantastatii=distantastatii;
        }
        int getNrlinie() const 
        {
            return nrlinie;
        }
        double incasari(int nrpasageri) override
            {
                return nrpasageri*2;
            }
        double kilometri() override
            {
                return nrstatii*distantastatii;
            }

};

class Troleibuz: public Transport
{
    private:
        int nrlinie, nrstatii;
        double distantastatii;
    public: 
        Troleibuz()=default;
        Troleibuz(int nrlinie, int nrstatii, double distantastatii){
            this-> nrstatii=nrstatii;
            this-> nrlinie=nrlinie;
            this-> distantastatii=distantastatii;
        }
        int getNrlinie() const 
        {
            return nrlinie;
        }
        double incasari(int nrpasageri) override
            {
                return nrpasageri*2;
            }
        double kilometri() override
            {
                return nrstatii*distantastatii;
            }

};

class Autobuz: public Transport
{
    private:
        int nrlinie, nrstatii;
        double distantastatii;
    public: 
        Autobuz()=default;
        Autobuz(int nrlinie, int nrstatii, double distantastatii){
            this-> nrstatii=nrstatii;
            this-> nrlinie=nrlinie;
            this-> distantastatii=distantastatii;
        }
        int getNrlinie() const 
        {
            return nrlinie;
        }
        double incasari(int nrpasageri) override
            {
                return nrpasageri*2;
            }
        double kilometri() override
            {
                return nrstatii*distantastatii;
            }

};

class Angajati
{
    protected:
        std::string nume;
    public:
        virtual double salariu(const STB& stb) const =0;
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

        void adaugaLinie(int linie) 
        {
            linii.push_back(linie);
        }
        double salariu(const STB& stb) const override
        {
            double totalKilometri = 0.0;
            // std::vector<Transport*> vehicule=stb.getVehicule();
            // for (int linie : linii) 
            // {
            //     for (Transport* vehicul : vehicule) 
            //     {
            //     if (Tramvai* tramvai = dynamic_cast<Tramvai*>(vehicul)) {
            //         if (tramvai->getNrlinie() == linie) 
            //             totalKilometri += tramvai->kilometri();
            //         }
            //     }
            // }
            return totalKilometri * 0.75;
        }
        void afisare()
        {
            for(int i=0; i<nrlinii;i++)
                std::cout<<linii[i]<<", ";
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
        void adaugaLinie(int linie) 
        {
            linii.push_back(linie);
        }

        double salariu(const STB& stb) const override
        {
            double suma = 0.0;
            // std::vector<Transport*> vehicule=stb.getVehicule();
            // for (int linie : linii) 
            // {
            //     for (Transport* vehicul : vehicule) 
            //     {
            //     if (Autobuz* autobuz = dynamic_cast<Autobuz*>(vehicul)) 
            //     {
            //         if (autobuz->getNrlinie() == linie) 
            //             suma += autobuz->kilometri()*0.95;
            //     }
            //     else if (Troleibuz* troleu = dynamic_cast<Troleibuz*>(vehicul)) 
            //     {
            //         if (troleu->getNrlinie() == linie) 
            //             suma += troleu->kilometri()*0.95;
            //     }
            //     }
            // }
            return suma;
        }
        void afisare()
        {
            for(int i=0; i<nrlinii;i++)
                std::cout<<linii[i]<<", ";
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

        void adaugaLinie(int linie) 
        {
            linii.push_back(linie);
        }
        double salariu(const STB& stb) const override
        {
            return nramenzi*0.25;
        }
        void afisare()
        {
            for(int i=0; i<nrlinii;i++)
                std::cout<<linii[i]<<", ";
        }
};

class STB
{
    private: 
        std::vector<Transport*> vehicule;
        std::vector<Angajati*> personal;
        void adaugaTransport(Transport* transport) 
        {
            vehicule.push_back(transport);
        }
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
            for (Angajati* angajat : personal) 
            {
                if(Vatman* vatman = dynamic_cast<Vatman*>(angajat)) 
                {
                    if (vatman->getNume() == nume) 
                    {
                        if(cautaVehicul(linie)==nullptr)
                        {
                            int nrlinie, nrstatii;
                            double distantastatii;
                            std::cout << "Introduceti numarul de statii si distanta dintre statii: ";
                            std::cin>> nrstatii >> distantastatii;
                            Tramvai* tram= new Tramvai(linie, nrstatii, distantastatii);
                            adaugaTransport(tram);  
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
                                std::cout<<"Linie gresita. Vatmanul poate conduce doar tramvaie.";
                        }
                    }
                }
                else if(Sofer* sofer = dynamic_cast<Sofer*>(angajat)) 
                {
                    if (sofer->getNume() == nume) 
                    {
                        sofer->adaugaLinie(linie);
                        std::cout << "Acum circulati pe linia  " << linie << ".\n";
                        return; 
                    }
                }
                else if(Controlor* controlor = dynamic_cast<Controlor*>(angajat)) 
                {
                    if (controlor->getNume() == nume) 
                    {
                        controlor->adaugaLinie(linie);
                        std::cout << "Acum operati pe linia  " << linie << ".\n";
                        return; 
                    }
                }
                else 
                    std::cout << "Nu s-a gasit niciun angajat cu numele dat.\n";
            }
        }
    public:
    friend class Angajati;
        std::vector<Transport*> getVehicule() const 
        {
        return vehicule;
        }
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
        void traseu(Angajati *ang)
        {
            Vatman *vatman;
            Sofer *sofer;
            Controlor *controlor;
            if((vatman = dynamic_cast<Vatman*>(ang)) != nullptr)
                vatman->afisare();
            else if((sofer = dynamic_cast<Sofer*>(ang)) != nullptr)
                sofer->afisare();
            else if((controlor = dynamic_cast<Controlor*>(ang)) != nullptr)
                controlor->afisare();
            else
                std::cout<<"Angajat necunoscut.";
        }
        
        friend std::istream& citireangajat(std::istream& is, STB& stb);
        friend std::istream& actualizarereangajat(std::istream& is, STB& stb);
};

std::istream& citireangajat(std::istream& is, STB& stb)
{   //Functia de citire a farmacistilor.
    std::string numeAngajat, post;
    std::cout << "Cum va numiti?: ";
    getline(is, numeAngajat);
    std::cout << "Ce post aveti?(Vatman, Sofer sau Controlor): ";
    getline(is, post);
    if(post == "Vatman")
    {
        std::vector<int> linii;
        std::cout << "Introduceti numarul liniei pe care o sa circulati: ";
        is >> linii[0];
        if(stb.cautaVehicul(linii[0])==nullptr)
        {
            int nrlinie, nrstatii;
            double distantastatii;
            std::cout << "Introduceti numarul de statii si distanta dintre statii: ";
            is >> nrstatii >> distantastatii;
            Tramvai* tram= new Tramvai(linii[0], nrstatii, distantastatii);
            stb.adaugaTransport(tram);
            stb.adaugaVatman(numeAngajat, linii, 1);
        }
        else
        {
            Transport* vehiculPtr = stb.cautaVehicul(linii[0]); 
            // Verificam daca obiectul pointat e un tramvai.
            Tramvai* tramvaiPtr = dynamic_cast<Tramvai*>(vehiculPtr);
            if (tramvaiPtr) 
            {
            // Daca obiectul este un Tramvai, apelam adaugaVatman
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
        is >> linii[0];
        if(stb.cautaVehicul(linii[0])==nullptr)
        {
            int nrlinie, nrstatii;
            double distantastatii;
            std::cout << "Introduceti numarul de statii si distanta dintre statii: ";
            is >> nrstatii >> distantastatii;
            if(tip=="Autobuz")
            {
                Autobuz* autobuz= new Autobuz(linii[0], nrstatii, distantastatii);
                stb.adaugaTransport(autobuz);
                stb.adaugaSofer(numeAngajat, linii, 1);
            }
            else
            {
                Troleibuz* troleu= new Troleibuz(linii[0], nrstatii, distantastatii);
                stb.adaugaTransport(troleu);
                stb.adaugaSofer(numeAngajat, linii, 1);
            }
        }
        else
        {
            Transport* vehiculPtr = stb.cautaVehicul(linii[0]); 
            // Verificam daca obiectul pointat e un tramvai.
            Autobuz* autobuzPtr = dynamic_cast<Autobuz*>(vehiculPtr);
            if (autobuzPtr) 
            {
            // Daca obiectul este un Autobuz, apelam adaugaVatman
                stb.adaugaSofer(numeAngajat, linii, 1);
            }
            else
                std::cout<<"Linie gresita. Soferul poate conduce doar autobuze sau troleibuze.";
        }
    } 
    else if (post == "Controlor") 
    {
        std::vector<int> linii={};
        std::cout << "Introduceti numarul liniei pe care veti opera: ";
        is >> linii[0];
        stb.adaugaControlor(numeAngajat, 0, linii, 1);
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
    std::cout << "Cum va numiti?: ";
    getline(is, numeAngajat);
    std::cout << "Ce linie vreti sa operati?: ";
    int nrlinie;
    is >> nrlinie;
    stb.actualizeazaAngajat(numeAngajat,nrlinie);
    return is;
}

int main()
{
    STB stb;
    citireangajat(std::cin,stb);
    // Tramvai tramvai(21,10,2);
    // Tramvai tramvai1(41,40,1.5);
    // std::vector<int> linii={21,41,36};
    // Controlor controlor("Gabi",47,linii,3);
    // Vatman vatman("Ion",linii,3,tramvai);
    return 0;
}