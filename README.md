# Analisi Empirica degli Algoritmi di Ordinamento

Questo progetto esegue un'analisi empirica degli algoritmi di ordinamento: Insertion Sort, Selection Sort, Bubble Sort e Merge Sort, scritti in C++. 
L'obiettivo è confrontare le prestazioni di questi algoritmi in termini di tempo di esecuzione su dataset di diverse dimensioni e caratteristiche.

## Struttura del Progetto
sort/: Contiene il codice sorgente degli algoritmi di ordinamento e degli script per l'analisi.

* algSort.cpp 
  ```
  Corpo delle funzioni sort
  ```
* algSort.h
  ```
  Dichiarazione delle funzioni
  ```

tempi_di_esecuzione.csv: Contiene i risultati dell'analisi (tempi di esecuzione, grafici, ecc.).

* l'ordine del CSV è :
  ```
  dimensione,selection,insertion,bubble,mergeBU
  ```
* per scrivere su file: funzione writeToFile in algSort.cpp


README.md: Documentazione del progetto.

### Requisiti

```
Compilatore C++ (ad esempio, g++)
```


## Esecuzione

Una volta compilato il progetto, puoi eseguire l'analisi comparativa degli algoritmi di ordinamento

# Crediti

Per renderizzare le grafiche Dear ImGui: https://github.com/ocornut/imgui

Per i grafici (plot) ImPlot: https://github.com/epezent/implot
