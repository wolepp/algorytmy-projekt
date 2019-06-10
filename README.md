# ProjektAlgorytmy
ProjektAlgorytmy to program rozwiązujący problem szeregowania zadań korzystający z programowania genetycznego.
Projekt składa się z 3 głównych części: Graf, Drzewo, PrzydzialZasobow.

Graf jest to implementacja grafu zadań wczytywanego z pliku. Wczytany graf (za pomocą klasy Wczytywanie) jest
przechowywany w postaci mapy, w której do wierzchołków jest przypisana struktura Info zawierająca szczegółowe informacje na temat
danego wierzchołka (czasy oraz koszty na poszczgólnych zasobach oraz informację o dzieciach).
W klasie zawarte są także niezbędne metody.

Drzewo to implementacja drzewa będącego genotypem zawierającego wierzchołki, które zawierają decyzje - geny. Każdy
wierzchołek Node posiada informacje o dzieciach i swoje id.

PrzydzialZasobow zawiera mapę, w której do wierzchołka grafu przydzielony jest zasób. Klasa zawiera także
implementację metod służących do odnalezienia zasobu danego wierzchołka (lub na odwrót) oraz przydzielenie
zasobu do wierzchołka.

W funkcji main kolejno wczytujemy graf z pliku w postaci listy sąsiedztwa. Nastepnie pobieramy od użytkownika
wszystkie niezbędne parametry (przy użyciu klasy Interfejs).


Program kończy się w momencie kiedy ilość pokoleń będzie wieksza od parametru epsilon **NIE, nie kończy się wtedy :P**. Rozwiązaniem jest osobnik,
dla którego funkcja dopasowania będzie miała najmniejszą wartość.

## Użycie
Kompilacja
```
make 
```

## Autorzy
* **Aleksandra Chrzanowska**
* **Małgorzata Gwinner**
* **Wojciech Lepich**
* **Radosław Dyrcz**
