#include <iostream>
#include <locale.h>
#include <vector>
#include <string.h>

using namespace std;

class SortAlgorithms {
    public:
        SortAlgorithms();
        void InsertionSort(std::vector<double> &items);
        void showIterarion(std::vector<double>, int);
};

/** Constructor */
SortAlgorithms::SortAlgorithms() {

}

void SortAlgorithms::InsertionSort(std::vector<double> &items){
    double key;
    int comparaciones = 0;
    int j;
    for (int i = 1; i < items.size(); i++){
        key = items[i];
        j = i - 1;

        while(j >= 0 && items[j] > key){
            items[j + 1] = items[j];
            j--;
            comparaciones ++;
        }
        items[j + 1] = key;
        comparaciones++;
        showIterarion(items, i);
    }
    cout << "Comparaciones: " << comparaciones << endl;
}

void SortAlgorithms::showIterarion(std::vector<double> items, int noI){
    if(noI == 0) cout << "\nOrden inicial: ";
    else cout << "\nIteración " << noI << ": ";

    /** Muestra en pantalla el oden de los valores despes de cada recorrido */
    for( int i = 0; i < items.size(); i++ ){
        if( i == items.size()-1 ){
                cout << items[i] << ", " << endl;
        }else{
            cout << items[i] << ", ";
        }
    }
}

int main()
{
    // Admición de caracteres especiales
    setlocale(LC_CTYPE, "Spanish");
    cout << "Insertion Sort" << endl;
    cout << "García Martínez Braulio Israel 220331615" << endl;

    SortAlgorithms sortA = SortAlgorithms();

    /** Definición de la longitud del vector */
    int noe;
    do{
        cout << "Ingrese la cantidad de datos que desea ordenar: ";
        cin >> noe;

        if( (noe < 2) || (noe >100) ){
            cout << "La cantidad mínima de elementos a ordenar son 2 y la cantidad máxima son 100" << endl;
        }
    }while( (noe < 2) || (noe > 100) );

    /** Ingreso de datos al vector */
    std::vector<double> items(noe);
    double value;
    for( int i = 0; i < items.size(); i++ ){
        cout << "Ingrese el valor " << i+1 << ": ";
        cin >> value;
        items[i] = value;
    }

    sortA.InsertionSort(items);
    return 0;
}
