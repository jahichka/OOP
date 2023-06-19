/*Implementirati generičku funkciju sort(p,k,f) koja kao argumente uzima početak i kraj sekvence
koju treba sortirati [p,k) te binarnu predikat funkciju f(a,b) koja definiše kriterij za sortiranje.
Binarna predikat funkcija vraća tačnu vrijednost ukoliko element a treba u sekvenci biti prije
elementa b, u suprotnom vraća netačno. Ukoliko se funkcija sort pozove bez trećeg argumenta
(pozove se sort(p,k)), elemente sortirati od manjeg ka većem. Funkciju sort definisati u
namespace-u my, u zaglavlju my.hpp.
Pseudo-kod algoritma za sortiranje kojeg implementira funkcija sort, skupa sa primjerima koji
uključuju animaciju može se naći na adresi: https://visualgo.net/en/sorting.
Funkciju testirati pomoću file-a test.cpp datog u prilogu zadaće. Obratiti pažnju na činjenicu da
file-ovi test.cpp, my.hpp i doctest.h (nalazi se u prilogu zadaće) moraju biti u istom direktoriju. Na
linku se nalazi poziv izvršnog file-a sa ispravno napisanom funkcijom sort.*/
