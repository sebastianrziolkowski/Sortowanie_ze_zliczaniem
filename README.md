# Wyniki testów

![alt text](https://raw.githubusercontent.com/sebastianrziolkowski/Sortowanie_ze_zliczaniem/master/Sortowanie%20ze%20zliczaniem.bmp)

# Sortowanie_ze_zliczaniem
<p>
W pewnym doświadczeniu zebrano dane pewnych pomiarów całkowitoliczbowych dodatnich. Dodatkowym parametrem w tym doświadczeniu była krotność wystąpień odpowiedniej wartości.
</p>
<p>
Zadanie programisty polega na wczytaniu danych, będących parami (pomiar, krotność), posortowanie ich w porządku rosnących pomiarów, a następnie wykorzystanie posortowanej tablicy danych do odszukiwania określonych krotności pomiarów.
</p>
Bardziej szczegółowo:
<ul>
    <li>program otrzymuje na wejściu pewną liczbę tablic do posortowania</li>
    <li>pierwszym zadaniem programu jest posortowanie każdej z nich w porządku rosnących pomiarów i wyświetlenie na standarowe wyjście</li>
    <li>następnym zadaniem programu jest "połączenie" wszystkich posortowanych tablic w jedną dużą tablicę (posortowaną w tym samym porządku) i zwrócenie jej na standardowe wyjście</li>
    <li>ostatnim zadaniem jest wyszukanie zadanych pomiarów w posortowanej tablicy par (pomiar, krotność), gdzie każdorazowo program dostanie do odszukania pomiar, a wyświetlić powinien jego krotność lub 0, jeśli liczba nie występuje w posortowanej tablicy</li>
</ul>

<p>
Proces sortowania jest specyficzny, ponieważ nie dopuszcza się powtórzeń pomiarów w tablicy wynikowej. Jeśli zostaną znalezione dwa elementy w tablicy o tym samym pomiarze, należy "złączyć" je w jedną komórkę o krotności będącej sumą krotności poszczególnych elementów. Np:
</p>
<p>
  dla wejściowego ciągu danych (dla czytelności krotność w nawiasach)
</p>
<pre>
12(3) 5(2) 10(1) 5(4)
</pre>
<p>
  Ciąg posortowany powinien wyglądać tak:
</p>
<pre>
5(6) 10(1) 12(3)
</pre>

<h2>Dane wejściowe</h2>
<ul>
    <li>w pierwszym wierszu liczba tablic do posortowania</li>
    <li>następnie dla każdej tablicy
    <ul>
        <li>liczba pomiarów (rozmiar tablicy),</li>
        <li>pary elementow (pomiar, krotność), rozdzielone znakami białymi</li>
    </ul></li>
    <li>następnie liczba pomiarów do wyszukania</li>
    <li>sekwencja tych pomiarów rozdzielona znakami białymi</li>
</ul>
<p>
Wszystkie wielkości są liczbami całkowitymi, większymi od 0, mieszczącymi się w typie całkowitym 4-bajtowym bez znaku. Poszczególne krotności są na tyle małe, że ich suma (dla tego samego pomiaru) również mieści się w typie 4-bajtowym bez znaku.
</p>

<h2> Wyjście </h2>
<p>
Wymagany format wyjścia (wyświetlenia) każdej z tablic jest identyczny jak format wejścia. Liczba znaków białych rozdzielających poszczególne elementy wyjścia nie ma znaczenia.
</p>

<h2>
Dodatkowe wymagania
</h2>
<ul>
    <li>sortowanie pojedynczej tablicy powinno mieścić się w czasie <span class="math">O(n<sup>2</sup>)</span> (jako bazę algorytmu można wykorzystać dowolny znany algorytm)</li>
    <li>w przypadku otrzymania na wejściu tablicy posortowanej, algorytm sortowania powinien mieścić się w czasie <span class="math">O(n)</span></li>
    <li>algorytm mergingu dwóch posortowanych tablic powinien mieć złożoność liniową
    (przy długościach tablic odpowiednio <span class="math">n</span> i <span class="math">m</span> mieścić się w czasie <span class="math">O(n+m)</span>)</li>
    <li>wyszukiwanie w posortowanej tablicy powinno mieścić się w czasie logarytmicznym <span class="math">O(ln n)</span></li>
</ul>

<h2>Przykład</h2>
<p>
Dane wejściowe, składające się z 4 tablic oraz 5 liczb do odszukania:
</p>
<pre>
4
 4  199 3 213 2 312 4 324 2
 6  79 2 32 1 312 5 24 2 75 10 24 3
 4  119 4 413 2 112 4 54 2
 6  19 1 32 2 312 4 34 7 13 2 19 3
5
10 19 3 75 77
</pre>
<p>
Oczekiwany wynik (najpierw każda z 4 posortowanych tablic, następnie jedna "złączona" tablica ze wszystkimi danymi, na koniec wyszukane krotności pomiarów z ostatniej linii wejścia):
</p>
<pre>
4  199 3 213 2 312 4 324 2
5  24 5 32 1 75 10 79 2 312 5
4  54 2 112 4 119 4 413 2
5  13 2 19 4 32 2 34 7 312 4
15 13 2 19 4 24 5 32 3 34 7 54 2 75 10 79 2 112 4 119 4 199 3 213 2 312 13 324 2 413 2
0 4 0 10 0
</pre>


Zadanie pochodzi z kursu uczelni UMCS
tichy.umcs.lublin.pl
