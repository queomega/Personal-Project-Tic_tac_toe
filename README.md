Descriere
Acesta este un proiect simplu care implementeaza jocul clasic "X si 0" (Tic-Tac-Toe) folosind limbajul de programare C. In acest joc, jucatorul se confrunta cu computerul, iar cine incepe este decis prin aruncarea unui zar. Jucatorul poate alege sa joace cu "X" sau "0", iar restul jocului se desfasoara pe rand, fiecare alegand o pozitie pe tabla de joc.

Functionalitati
Decizia cine incepe: Atat jucatorul, cat si computerul arunca un zar, iar cel cu numarul mai mare incepe.
Alegerea simbolului: Jucatorul alege daca joaca cu "X" sau "0" daca incepe el, iar computerul primeste simbolul opus.
Tabla interactiva: Mutarile sunt introduse de jucator (linie si coloana), iar tabla este actualizata dupa fiecare tur.
Computerul joaca aleatoriu: Computerul isi alege pozitia libera in mod aleator.
Castigator: Jocul detecteaza automat cand unul dintre jucatori castiga si afiseaza rezultatul.

Cum sa rulezi jocul

Compilare: Foloseste un compilator C pentru a compila codul. De exemplu, folosind gcc:
gcc -o tic_tac_toe tic_tac_toe.c
./tic_tac_toe


Cum se joaca
Aruncarea zarului: La inceput, jucatorul si computerul arunca zarul pentru a decide cine incepe. Daca zarul jucatorului este mai mare, acesta incepe.

Alegerea simbolului: Daca jucatorul incepe, el poate alege daca joaca cu "X" sau "0". Daca incepe computerul, simbolul este ales aleatoriu.

Mutari: Jucatorul alege linia si coloana unde vrea sa puna simbolul. Tabla este actualizata si urmeaza mutarea computerului.

Castigatorul: Dupa fiecare mutare, jocul verifica daca cineva a castigat. Jocul continua pana cand unul dintre jucatori castiga sau tabla se umple.

Scorul: Dupa ce un joc se incheie, scorul este actualizat si poti alege daca vrei sa mai joci o runda.

Structura codului
Functii principale
firstPick(): Decide cine incepe jocul printr-o aruncare de zar.
choice(): Alege simbolul "X" sau "0" in functie de cine incepe.
game(): Functia care ruleaza logica jocului, alternand intre jucator si computer.
main(): Initializarea jocului si controlul buclei de joc (ofera optiunea de a juca din nou).
