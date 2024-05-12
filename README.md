Pentru a doua tema am ales sa gestionez Societatea de Transport Bucuresti, deoarece puteam implementa cu sens principiul mostenirii. 
Sistemul se deschide zilnic pentru angajatii care se prezinta la lucru si retine toate activitatiile de pe parcursul zilei. Cand un vatman sau un sofer nou se logheaza trebuie sa introduca linia pe care vor opera. Doar soferii si vatmanii pot introduce noi linii, in timp ce controlori pot opera doar pe liniile deja puse in circulatie (logic din moment ce un controlor nu se poate urca la control intr un vehicul care nu se afla in circulatie). Cand un sofer sau un vatman schimba linia cu una deja existenta, se verifica daca tipul de vehicul este compatibil (vatmanii pot conduce doar tramvaie, soferii doar autobuze sau troleibuze, iar controlorii pot opera pe orice). Controlorii pot da amenzi pe parcursul zilei.
Salariul vatmanilor si soferilor se calculeaza in functie de lungimea totala a traseelor liniilor operate inmultite cu pretul pe km, iar controlorii sunt pontati in functie de nr de amenzi.
Cand afisam informatiile despre vehicule se calculeaza incasarile (fiecare tip de vehicul are tariful lui) si nr aproximativ de pasageri inmultind lungimea traseului liniei cu o medie de calatori.
Am folosit o functie statica ca sa setam data de azi.
Clasele Angajati si Transport sunt interfete.
Avem functii pure pentru nr pasageri, lungimile traseelor si orele lucrate.
Clasele Vatman, Sofer si Controlor mostenesc clasa Angajati.
Clasele Tramvai, Autobuz, Troleibuz mostenesc clasa Transport.
Am folosit dynamic cast in repetate randuri pentru a afla tipul de vehicul sau de angajat in metodele mele.
Vectorii pentru vehicule si personal sunt alocati dinamic.
