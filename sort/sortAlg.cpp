#include "sortAlg.h"


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void writeToFile(int size, int selectionTime, int insertionTime, int bubbleTime, int mergeTime){
    std::ofstream file;
    
    file.open("tempi_di_esecuzione.csv", std::ios_base::app);
    if (file.is_open()) {
        file << size << "," << selectionTime << "," << insertionTime << "," << bubbleTime << ","<< mergeTime << "\n";
        file.close();
    }
    else {
        std::cout << "Impossibile aprire il file.\n";
    }
}

void selectionSort(int arr[], int n) {
    int i, j, minI;
    for (i = 0; i < n - 1; i++) {
        minI = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minI])
                minI = j;
        swap(&arr[minI], &arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void randFunz(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void merge(int a[], int lo, int mid, int hi, int LA) {
    // fusione di a [ lo ... mid ] con a [ mid +1... hi ]
    int* aux = new int[LA]; // LA lunghezza di a []
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++) aux[k] = a[k];
    for (int k = lo; k <= hi; k++)
        if (i > mid) a[k] = aux[j++];
        else if (j > hi) a[k] = aux[i++];
        else if (aux[j] < aux[i]) a[k] = aux[j++];
        else a[k] = aux[i++];
    delete[] aux;

}

void mergesortBU(int a[], int lo, int hi, int size) {
    // lo indice sinistro , hi indice destro
    int i, sz, appo; // sz , size = dimensione
    for (sz = 1; sz <= hi - lo; sz = sz + sz)
        for (i = 0; i <= hi - sz; i = i + (sz + sz)) {
            if (i + (sz + sz) - 1 < hi) appo = i + (sz + sz) - 1;
            else appo = hi;
            merge(a, i, i + sz - 1, appo, size);
        }

}

void pushArr(int* array, int nElementi, int value)
{
    array[nElementi] = value;
    
}

void resetArray(int array[], int nElementi)
{
	for (int i = 0; i < nElementi; i++) {
		array[i] = 0;
	}
}

void readFromFile(int tempiInsertion[], int tempiSelection[], int tempiBubble[], int tempiMerge[], int* contaElementi)
{
	std::ifstream file;
	file.open("tempi_di_esecuzione.csv");
    if (file.is_open()) {
        MessageBox(NULL, "Testo2", "Titolo", 1);
        std::string line;
		std::string temp;
		int i = 0;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::getline(ss, temp, ','); // Salta la prima colonna
            std::getline(ss, temp, ',');
            tempiSelection[i] = std::stoi(temp);
            std::getline(ss, temp, ',');
            tempiInsertion[i] = std::stoi(temp);
            std::getline(ss, temp, ',');
            tempiBubble[i] = std::stoi(temp);
            std::getline(ss, temp, ',');
            tempiMerge[i] = std::stoi(temp);
            i++;
        }

		file.close();
        		*contaElementi = i;
    }
    else {
        MessageBox(NULL, "Testo", "Titolo", 1);
		
	}
	
}

void runSort(int* insertionTime, int* selectionTime, int* bubbleTime, int* mergeTime, int nElementi)
{

    cout << globals.dimensioneArray << endl;
    int* arr = new int[globals.dimensioneArray];
    randFunz(arr, globals.dimensioneArray);

    int* selectionArr = new int[globals.dimensioneArray];
    int* insertionArr = new int[globals.dimensioneArray];
    int* bubbleArr = new int[globals.dimensioneArray];
    int* mergeArr = new int[globals.dimensioneArray];

    //copia array
    for (int i = 0; i < globals.dimensioneArray; i++) {
        selectionArr[i] = arr[i];
        insertionArr[i] = arr[i];
        bubbleArr[i] = arr[i];
        mergeArr[i] = arr[i];
    }

    int selectionTime0, insertionTime0, bubbleTime0, mergeTime0;
    selectionTime0 = time(NULL);
    selectionSort(selectionArr, globals.dimensioneArray);
    selectionTime0 = time(NULL) - selectionTime0;

    insertionTime0 = time(NULL);
    insertionSort(insertionArr, globals.dimensioneArray);
    insertionTime0 = time(NULL) - insertionTime0;

    
    bubbleTime0 = time(NULL);
    bubbleSort(bubbleArr, globals.dimensioneArray);
    bubbleTime0 = time(NULL) - bubbleTime0;

    mergeTime0 = time(NULL);
    mergesortBU(mergeArr, 0, globals.dimensioneArray - 1, globals.dimensioneArray);
    mergeTime0 = time(NULL) - mergeTime0;


    if (globals.dimensioneArray != 0) {
        writeToFile(globals.dimensioneArray, selectionTime0, insertionTime0, bubbleTime0, mergeTime0);
        pushArr(insertionTime, nElementi, insertionTime0);
        pushArr(selectionTime, nElementi, selectionTime0);
        pushArr(bubbleTime, nElementi, bubbleTime0);
        pushArr(mergeTime, nElementi, mergeTime0);
    }


    delete[] selectionArr;
    delete[] insertionArr;
    delete[] bubbleArr;
    delete[] mergeArr;
    delete[] arr;
}